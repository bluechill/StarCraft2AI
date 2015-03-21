//
//  ARBtoOpenCL.h
//  StarCraft2API
//
//  Created by Alex Turner on 2/6/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__ARBtoOpenCL__
#define __StarCraft2API__ARBtoOpenCL__

#include <vector>
#include <string>
#include <ostream>

namespace OpenGL
{
	class ConvertToOpenCL
	{
	public:
		virtual void load(std::vector<std::string> program_lines, unsigned long hash) = 0;
		virtual const std::string get_name() { return name; }
		
		virtual void output(std::ostream& output_file) = 0;
		
	protected:
		std::string name;
	};
	
	class ARBtoOpenCL : public ConvertToOpenCL
	{
	public:
		virtual void load(std::vector<std::string> program_lines, unsigned long hash);
		virtual void output(std::ostream& output_file);
		
	private:
		std::vector<std::string> opencl_program;
		
		enum arb_instruction_type
		{
			PARAM,
			VARIABLE,
			SCALAR_INSTRUCTION,
			VECTOR_INSTRUCTION
		};
		
		enum base_type
		{
			float4_ptr,
			float4_array,
			float4,
			float1
		};
		
		struct arb_instruction
		{
			bool is_declaration = false;
			
			virtual ~arb_instruction() {}
		};
		
		struct declaration : public arb_instruction
		{
			declaration()
			{
				this->is_declaration = true;
			}
			
			base_type type;
			std::string name;
			
			std::vector<std::string> assignment;
		};
		
		struct instruction : public arb_instruction
		{
			arb_instruction_type type;
			
			std::string function_name;
			std::string swizzle;
			
			std::string output_variable;
			std::vector<std::string> input_variables;
		};
		
		std::vector<std::string> split_string(std::string str, char delim);
		void replaceAll(std::string& str, const std::string& from, const std::string& to);
		arb_instruction_type instruction_type(std::string instruction);
		arb_instruction* convert_ARB_instruction_to_OpenCL(std::string line);
		void convert_param_instruction(declaration& param, int& line, std::vector<std::string>& program_lines);
		void handle_truncation(instruction& ins);
		std::vector<std::string> print_declaration(declaration* dec);
		std::vector<std::string> print_instruction(instruction* ins);
		std::vector<std::string> print_arb_instruction(arb_instruction& ins);
	};
}

#endif /* defined(__StarCraft2API__ARBtoOpenCL__) */
