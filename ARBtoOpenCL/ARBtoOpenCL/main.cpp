//
//  main.cpp
//  ARBtoOpenCL
//
//  Created by Alex Turner on 2/3/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <cassert>

using namespace std;

#include "ARBtoOpenCL.h"
using namespace OpenGL;

#include "xxhash.h"

int main(int argc, const char * argv[])
{
	std::string name = "";
	
	std::vector<std::string> program_lines;
	size_t hash;
	
	std::string loader_path = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/SC2 Info/SC2Shaders/FlashVertexMain-3040141427.arb";
	
	ifstream loader_file(loader_path);
	
	string line;
	std::string program_string;
	while (std::getline(loader_file, line))
	{
		program_lines.push_back(line);
		program_string += line + "\n";
	}
	
	hash = XXH32(program_string.c_str(), program_string.length(), 0xDEADBEEF);
	
	ConvertToOpenCL* converter = new ARBtoOpenCL;
	converter->load(program_lines, hash);
	
	name = converter->get_name();
	
	std::string path = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/SC2 Info/SC2Shaders/" + name + "-" + to_string(hash) + ".cl";
	
	ofstream file(path);
	
	converter->output(file);
		
    return 0;
}
