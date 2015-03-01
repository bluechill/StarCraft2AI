//
//  ARBtoOpenCL.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 2/6/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "ARBtoOpenCL.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <cassert>

using namespace std;

namespace OpenGL
{
	std::vector<std::string> ARBtoOpenCL::split_string(std::string str, char delim )
	{
		std::vector<std::string> result;
		string tmp;
		string::iterator i;
		result.clear();
		
		for(i = str.begin(); i <= str.end(); ++i) {
			if((const char)*i != delim  && i != str.end())
				tmp += *i;
			else
			{
				result.push_back(tmp);
				tmp = "";
			}
		}
		
		return result;
	}
	
	void ARBtoOpenCL::replaceAll(std::string& str, const std::string& from, const std::string& to)
	{
		if(from.empty())
			return;
		size_t start_pos = 0;
		while((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
		}
	}
	
	ARBtoOpenCL::arb_instruction_type ARBtoOpenCL::instruction_type(std::string instruction)
	{
		if (instruction == "PARAM")
			return PARAM;
		else if (instruction == "ADDRESS" || instruction == "TEMP" || instruction == "ATTRIB" || instruction == "ALIAS")
			return VARIABLE;
		else if (instruction == "ARL")
			return SCALAR_INSTRUCTION;
		else
			return VECTOR_INSTRUCTION;
	}
	
	ARBtoOpenCL::arb_instruction* ARBtoOpenCL::convert_ARB_instruction_to_OpenCL(std::string line)
	{
		// line cannot be a PARAM line which can be multiple lines
		
		string instruction;
		
		string output_input_string;
		
		string output;
		vector<string> input;
		
		int i = 0;
		
		for (;line[i] != ' ' && i < line.size();++i);
		
		instruction = line.substr(0, i);
		
		if (i == line.size() || instruction == "#")
			return (arb_instruction*)0xDEADBEEF;
		else if (instruction == "END")
			return nullptr;
		
		arb_instruction_type type = instruction_type(instruction);
		output_input_string = line.substr(i+1, -1);
		vector<string> output_input;
		
		if (type == VECTOR_INSTRUCTION || type == SCALAR_INSTRUCTION)
			output_input = split_string(output_input_string, ',');
		else
			output_input = split_string(output_input_string, ' ');
		
		for (string& s : output_input)
		{
			if (s.size() > 0 && s[0] == ' ')
				s = s.substr(1, -1);
			
			if (s.size() > 0 && s.back() == ';')
				s.pop_back();
		}
		
		output = output_input[0];
		for (int i = 1;i < output_input.size();++i)
		{
			if (output_input[i] != "=")
			{
				if (output_input[i].find("[") != string::npos)
				{
					// Found array indexing
					string insert = "int(";
					string end = ")";
					size_t left_bracket = output_input[i].find("[")+1;
					output_input[i].insert(left_bracket, "int(");
					
					size_t right_bracket = output_input[i].find("]");
					output_input[i].insert(right_bracket, ")");
				}
				
				input.push_back(output_input[i]);
			}
		}
		
		if (type == PARAM)
		{
			declaration* dec = new declaration;
			dec->type = float4_array;
			dec->name = output;
			dec->assignment = input;
			
			return dec;
		}
		else if (type == VARIABLE)
		{
			declaration* dec = new declaration;
			
			if (instruction == "ALIAS" || instruction == "ATTRIB")
			{
				dec->type = float4_ptr;
				dec->name = output;
				
				if (input.size() == 1)
					dec->assignment = {"&" + input[0]};
			}
			else
			{
				dec->type = float4;
				dec->name = output;
				
				if (input.size() == 1)
					dec->assignment = {input[0]};
			}
			
			return dec;
		}
		else if (type == SCALAR_INSTRUCTION || type == VECTOR_INSTRUCTION)
		{
			struct instruction* ins = new struct instruction;
			ins->type = type;
			ins->function_name = instruction;
			ins->output_variable = output;
			ins->input_variables = input;
			
			return ins;
		}
		
		return (arb_instruction*)0xDEADBEEF;
	}
	
	void ARBtoOpenCL::convert_param_instruction(declaration& param, int& line, vector<string>& program_lines)
	{
		// line is the line param was created from
		
		if (param.assignment.size() > 0)
		{
			if (param.assignment[0] == "{" && param.assignment.back() != "}")
			{
				// Array Initializer that isn't on one line, need to modify
				++line;
				
				while (line < program_lines.size())
				{
					vector<string> split = split_string(program_lines[line], ' ');
					
					for (string& s : split)
						param.assignment.push_back(s);
					
					if (program_lines[line++].back() == ';')
						break;
				}
				--line;
				
				// Now it's all on one "line"
			}
			
			for (int i = 0;i < param.assignment.size();++i)
			{
				while (param.assignment[i][0] == ' ' || param.assignment[i][0] == '\t')
					param.assignment[i] = param.assignment[i].substr(1, -1);
				
				if (param.assignment[i].size() == 0)
				{
					param.assignment.erase(param.assignment.begin()+i);
					--i;
				}
				
				if (param.assignment[i].back() == ',' || param.assignment[i].back() == ';')
					param.assignment[i].pop_back();
				
				if (param.assignment[i].find(".") != string::npos)
				{
					// Check if it's a number
					if (isdigit(param.assignment[i][param.assignment[i].find(".")+1]))
						param.assignment[i] += "f";
				}
			}
			
			if (param.assignment[0] == "{")
			{
				// Convert to OpenCL syntax
				vector<string> opencl_assignment;
				
				int start = 1;
				
				if (param.assignment[1] != "{")
					start = 0; // Single initialization of float4
				else
					param.assignment.pop_back(); // Remove the terminating '}' to prevent weird float4 construct
				
				int depth = 0;
				int count = 0;
				string quadlet = "(float4)(";
				
				for (int i = start;i < param.assignment.size();++i)
				{
					if (param.assignment[i] == "{")
						++depth;
					else if (param.assignment[i] == "}")
					{
						--depth;
						
						for (;count < 4;++count)
							quadlet += "0,";
						
						quadlet.pop_back();
						quadlet += ")";
						opencl_assignment.push_back(quadlet);
						quadlet = "(float4)(";
						count = 0;
					}
					else if (param.assignment[i].find("program") != string::npos)
					{
						// Handle program.env and program.local
						size_t start = param.assignment[i].find(".")+1;
						size_t end = param.assignment[i].find("[");
						
						string type = param.assignment[i].substr(start, end-start);
						
						// handle program env
						if (param.assignment[i].find("..") != string::npos)
						{
							// Dynamic
							size_t first = param.assignment[i].find("[")+1;
							size_t second = param.assignment[i].find("..");
							size_t third = second + 2;
							size_t fourth = param.assignment[i].find("]");
							
							string start = param.assignment[i].substr(first, second - first);
							string end = param.assignment[i].substr(third, third - fourth);
							
							int start_num = stoi(start);
							int end_num = stoi(end);
							
							for (int i = 0;i < end_num - start_num+1;++i)
							{
								quadlet = "(float4)(program." + type + "[" + to_string(start_num + i) + "])";
								opencl_assignment.push_back(quadlet);
								quadlet = "(float4)(";
							}
						}
						else
						{
							size_t first = param.assignment[i].find("[")+1;
							size_t second = param.assignment[i].find("]");
							
							quadlet += "program." + type + "[" + param.assignment[i].substr(first, second-first);
							quadlet += "])";
							opencl_assignment.push_back(quadlet);
							quadlet = "(float4)(";
						}
					}
					else
					{
						quadlet += param.assignment[i] + ",";
						++count;
					}
				}
				
				param.assignment = opencl_assignment;
			}
		}
	}
	
	void ARBtoOpenCL::handle_truncation(instruction& ins)
	{
		if (ins.type == VECTOR_INSTRUCTION)
		{
			// Check for swizzling truncation
			size_t period_location;
			if ((period_location = ins.output_variable.find_last_of(".")) != string::npos)
			{
				// There's some specific assignment going on
				++period_location;
				
				string swizzle = ins.output_variable.substr(period_location, -1);
				
				if (swizzle.find("x") != string::npos ||
					swizzle.find("y") != string::npos ||
					swizzle.find("z") != string::npos ||
					swizzle.find("w") != string::npos)
					ins.swizzle = swizzle;
			}
		}
	}
	
	vector<string> ARBtoOpenCL::print_declaration(declaration* dec)
	{
		vector<string> result;
		
		string line;
		if (dec->type == float4_ptr)
			line += "float4* ";
		else
			line += "float4 ";
		
		line += dec->name + ";";
		
		result.push_back(line);
		
		if (dec->assignment.size() == 1)
			result.push_back(dec->name + " = " + dec->assignment[0]);
		else if (dec->assignment.size() > 1)
		{
			string modified_name = dec->name.substr(0, dec->name.find("["));
			
			for (int i = 0;i < dec->assignment.size();++i)
			{
				string& s = dec->assignment[i];
				
				result.push_back(modified_name + "[" + to_string(i) + "] = " + s + ";");
			}
		}
		
		return result;
	}
	
	vector<string> ARBtoOpenCL::print_instruction(instruction* ins)
	{
		string result = ins->output_variable + " = " + ins->function_name + "(";
		
		if (ins->input_variables.size() > 0)
		{
			for (string& s : ins->input_variables)
				result += s + ", ";
			
			result.pop_back();
			result.pop_back();
		}
		
		result += ")";
		
		if (ins->swizzle.size() >= 1 && ins->type == VECTOR_INSTRUCTION)
			result += "." + ins->swizzle;
		
		result += ";";
		
		return {result};
	}
	
	vector<string> ARBtoOpenCL::print_arb_instruction(arb_instruction& ins)
	{
		if (dynamic_cast<declaration*>(&ins) != 0)
			return print_declaration(dynamic_cast<declaration*>(&ins));
		else
			return print_instruction(dynamic_cast<instruction*>(&ins));
	}
	
	void ARBtoOpenCL::load(std::vector<std::string> program_lines, unsigned long hash)
	{		
		ifstream arb_instructions("/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/OpenGL State Machine/SC2Programs/ARBInstructions.cl");
		
		opencl_program.push_back("");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("// Converted from ARB instructions to OpenCL using ARBtoOpenCL of the SC2API project. //");
		opencl_program.push_back("// Converted using v1.0 of the SC2API ARB to OpenCL Converter.                        //");
		
		time_t t = time(0);
		struct tm * now = localtime( & t );
		
		string conversion_string = "// Converted on " + to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) +"/" + to_string(now->tm_year + 1900) + "                                                            ";
		
		while (conversion_string.size() < 86)
			conversion_string += " ";
		
		conversion_string += "//";
		
		opencl_program.push_back(conversion_string);
		
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("");
		
		
		opencl_program.push_back("");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("// BEGIN ARB Instructions Replacements for OpenCL.                                    //");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("");
		
		string line;
		while (getline(arb_instructions, line))
			opencl_program.push_back(line);
		
		opencl_program.push_back("");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("// END ARB Instructions Replacements for OpenCL.                                      //");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("");
		
		ifstream structures("/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/OpenGL State Machine/SC2Programs/Structures.cl");
		
		opencl_program.push_back("");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("// BEGIN SC2API Structure Definitions                                                 //");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("");
		
		while (getline(structures, line))
			opencl_program.push_back(line);
		
		opencl_program.push_back("");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("// END SC2API Structure Definitions                                                   //");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("");
		
		std::map<std::string, std::string> aliases;
		
		std::function<const std::string (std::string)> alias_to_string = [&aliases](const std::string potential) -> const std::string
		{
			if (aliases.find(potential)!= aliases.end())
				return aliases[potential];
			
			return potential;
		};
		
		std::function<std::string (const std::string, bool)> replaceAllProgram = [this](std::string input, bool vertex_program)
		{
			string line = input;
			
			replaceAll(line, "program.local", "program.local_env");
			
			replaceAll(line, "result.", "result->");
			replaceAll(line, "vertex.", "vertex->");
			replaceAll(line, "fragment.", "fragment->");
			
			if (vertex_program)
			{
				replaceAll(line, "vertex->weight.", "vertex->weight[0].");
				replaceAll(line, "vertex->color.", "vertex->color.primary.");
				replaceAll(line, "vertex->texcoord.", "vertex->texcoord[0].");
				replaceAll(line, "vertex->matrixindex.", "vertex->matrixindex[0].");
				
				replaceAll(line, "result->color.", "result->color.front.primary");
				replaceAll(line, "result->color.primary.", "result->color.front.primary");
				replaceAll(line, "result->color.secondary.", "result->color.front.secondary");
				replaceAll(line, "result->color.front.", "result->color.front.primary");
				replaceAll(line, "result->color.back.", "result->color.back.primary");
				replaceAll(line, "result->texcoord.", "result->texcoord[0].");
			}
			else
			{
				replaceAll(line, "fragment->color", "fragment->color.primary");
				replaceAll(line, "fragment->texcoord.", "fragment->texcoord[0].");
				
				// TODO: implement fragment.clip[n..o], not used in SC2.
				
				replaceAll(line, "result->color.", "result->color[0].");
			}
						
			return line;
		};
		
		bool vertex_program = false;
		
		for (int i = 0;i < program_lines.size();++i)
		{
			std::string line = program_lines[i];
			
			if (line.find("!!ARBvp") != string::npos)
				vertex_program = true;
			else if (line.find("!!ARBfp") != string::npos)
				vertex_program = false;
			else if (line.find("#program ") != string::npos)
			{
				// Program name
				size_t program = line.find("#program ");
				size_t end = line.find("\n", program);
				
				program += 9;
				
				name = line.substr(program, end-program);
				
				opencl_program.push_back("__kernel void " + name + " (__global float4* program_env, __global float4* program_local, __global float* vertex_attrib_array, __global unsigned int vertex_attrib_index_array_count, __global struct attrib_info* vertex_attrib_info_array, __global fragment_struct* fragment_array, __global float4* fragment_texcoord_array, __global unsigned int fragment_max_texcoord_size, __global result_struct* result_array, __global float4* result_texcoord_array, __global unsigned int result_texcoord_max_size,  __global float4* result_frag_color_array, __global unsigned int result_frag_color_max_size, const unsigned int count)");
				opencl_program.push_back("{");
				opencl_program.push_back("\tint global_identifier = get_global_id(0);");
				opencl_program.push_back("\tif (global_identifier < count)");
				opencl_program.push_back("\t{");
				
				opencl_program.push_back("");

				ifstream opencl_setup_code("/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/OpenGL State Machine/SC2Programs/OpenCLSetupCode.cl");

				while (getline(opencl_setup_code, line))
					opencl_program.push_back(line);
				
				opencl_program.push_back("");
				opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
				opencl_program.push_back("//                                                                                    //");
				opencl_program.push_back("// BEGIN SC2API Converted Code                                                        //");
				opencl_program.push_back("//                                                                                    //");
				opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
				opencl_program.push_back("");
			}
			else
			{
				arb_instruction* arb_ins = convert_ARB_instruction_to_OpenCL(line);
				
				if (arb_ins == (arb_instruction*)0xDEADBEEF)
				{
					opencl_program.push_back("//" + line);
					continue;
				}
				else if (arb_ins && arb_ins->is_declaration && dynamic_cast<declaration*>(arb_ins)->type == float4_array)
				{
					// PARAM
					declaration* dec = dynamic_cast<declaration*>(arb_ins);
					
					convert_param_instruction(*dec, i, program_lines);
				}
				else if (arb_ins && !arb_ins->is_declaration && dynamic_cast<instruction*>(arb_ins) != nullptr)
					handle_truncation(*dynamic_cast<instruction*>(arb_ins));
				else if (arb_ins == nullptr)
					break; // END instruction
				
				vector<string> multiline_instructions = print_arb_instruction(*arb_ins);
				
				for (string& s : multiline_instructions)
					opencl_program.push_back("\t\t" + replaceAllProgram(s, vertex_program));
				
				delete arb_ins;
			}
		}
		
		opencl_program.push_back("");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("// END SC2API Converted Code                                                          //");
		opencl_program.push_back("//                                                                                    //");
		opencl_program.push_back("////////////////////////////////////////////////////////////////////////////////////////");
		opencl_program.push_back("");
		
		opencl_program.push_back("\t}");
		opencl_program.push_back("}");
	}
	
	std::ostream& ARBtoOpenCL::operator<<(std::ostream& os)
	{
		for (string s : opencl_program)
			os << s << endl;
		
		return os;
	}
}