//
//  TextureDatabase.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "TextureDatabase.h"

#include <syslog.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "OpenGL State Machine.h"

#include "xxhash.h"
#include "lupng.h"

#include "rapidxml_print.hpp"

#include "Logging.h"

using namespace rapidxml;
using namespace std;

namespace OpenGL
{
	static const string texture_db_file = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2DB.xml";
	static const string texture_db_texture_folder = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2Textures/";
	
	static const string texture_db_root = "TextureDatabase";
	static const string texture_db_texture = "Texture";
	static const string texture_db_hash = "Hash";
	static const string texture_db_classification = "Classification";
	static const string texture_db_classification_unknown = "Unknown";
	
	TextureDatabase::TextureDatabase()
	: setup(false)
	{}
	
	void TextureDatabase::setup_db()
	{
		errno = 0;
		FILE* db_file = fopen(texture_db_file.c_str(), "r");
		char *source = NULL;
		if (db_file != NULL) {
			/* Go to the end of the file. */
			if (fseek(db_file, 0L, SEEK_END) == 0) {
				/* Get the size of the file. */
				long bufsize = ftell(db_file);
				if (bufsize == -1) { /* Error */ }
				
				/* Allocate our buffer to that size. */
				source = new char[bufsize];
				
				/* Go back to the start of the file. */
				if (fseek(db_file, 0L, SEEK_SET) != 0) { /* Error */ }
				
				/* Read the entire file into memory. */
				size_t newLen = fread(source, sizeof(char), bufsize, db_file);
				if (newLen == 0) {
					SC2::Utilities::console_log("Error reading file", stderr);
				} else {
					source[++newLen] = '\0'; /* Just to be safe. */
				}
			}
			else
				SC2::Utilities::console_log("Empty DB");
			
			fclose(db_file);
		}
		
		try {
			char* contents = db_xml.allocate_string(source);
			db_xml.parse<0>(contents);
		} catch (rapidxml::parse_error& e) {
			SC2::Utilities::console_log("Failed to parse DB: %s : %s", e.what(), e.where<char>());
		}
		
		xml_node<> *root = db_xml.first_node(texture_db_root.c_str());
		
		if (!root)
		{
			char* node_name = db_xml.allocate_string(texture_db_root.c_str());
			xml_node<>* node = db_xml.allocate_node(node_element, node_name);
			db_xml.append_node(node);
			root = node;
		}
		
		for (xml_node<>* node = root->first_node(texture_db_texture.c_str()); node; node = node->next_sibling())
		{
			string hash_str = node->first_attribute(texture_db_hash.c_str())->value();
			string classification = node->first_attribute(texture_db_classification.c_str())->value();
			
			Texture new_texture(hash_str, classification);
			
			sc2api_textures.insert(new_texture);
		}
	}
	
	bool TextureDatabase::has_texture(GLuint texture)
	{
		if (!setup)
		{
			setup_db();
			setup = true;
		}
		
		return opengl_textures.find(texture) != opengl_textures.end();
	}
	
	void TextureDatabase::create_texture(GLuint texture)
	{
		if (!setup)
		{
			setup_db();
			setup = true;
		}
		
		if (!has_texture(texture))
		{
			// New texture
			GLint width, height;
			GLenum type = StateMachine::Shared.m_texture_units[StateMachine::Shared.m_active_texture].first;
			
			glGetTexLevelParameteriv(type, 0, GL_TEXTURE_WIDTH, &width);
			glGetTexLevelParameteriv(type, 0, GL_TEXTURE_HEIGHT, &height);
			
			if (width != 0 && height != 0)
			{
				GLubyte* pixels = new GLubyte[width*height*4];
				glGetTexImage(type, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
				
				unsigned int hash = XXH32(pixels, width*height*4, 0xDEADBEEF);
				
				// Find the hash
				Texture tex(to_string(hash), texture_db_classification_unknown);
				auto result = sc2api_textures.find(tex);
				
				if (result == sc2api_textures.end())
				{
					// Truly new texture
					string file_name = texture_db_texture_folder;
					file_name += to_string(hash);
					file_name += ".png";
					
					FILE* file = fopen(file_name.c_str(), "wb");
					
					LuImage* image = luImageCreate(width, height, 4, 8);
					image->data = pixels;
					luPngWrite([](const void *ptr, size_t size, size_t count, void *userPtr)
							   {
								   return fwrite(ptr, size, count, (FILE*)userPtr);
							   }, file, image);
					
					fclose(file);
					delete[] pixels;
					
					sc2api_textures.insert(tex);
					
					// Add it to the XML document
					xml_node<> *root = db_xml.first_node(texture_db_root.c_str());
					
					if (!root)
					{
						char* node_name = db_xml.allocate_string(texture_db_root.c_str());
						xml_node<>* node = db_xml.allocate_node(node_element, node_name);
						db_xml.append_node(node);
						root = node;
					}
					
					xml_node<>* texture_node = db_xml.allocate_node(node_element, texture_db_texture.c_str());
					char* hash_str = db_xml.allocate_string(to_string(hash).c_str());
					xml_attribute<>* hash_attr = db_xml.allocate_attribute(texture_db_hash.c_str(), hash_str);
					xml_attribute<>* classification_attr = db_xml.allocate_attribute(texture_db_classification.c_str(), texture_db_classification_unknown.c_str());
					
					texture_node->append_attribute(hash_attr);
					texture_node->append_attribute(classification_attr);
					
					root->append_node(texture_node);
					
					// Write the DB to disk
					
					ofstream out(texture_db_file, std::ios::out);
					
					string contents;
					
					rapidxml::print(back_inserter(contents), db_xml);
					
					out << contents;
					
					out.close();
				}
				
				opengl_to_sc2api[texture] = hash;
				opengl_textures.insert(StateMachine::Shared.m_texture_units[StateMachine::Shared.m_active_texture].second);
			}
		}
	}
	
	const Texture& TextureDatabase::get_texture(GLuint texture)
	{
		if (!setup)
		{
			setup_db();
			setup = true;
		}
		
		if (!has_texture(texture))
			return empty_texture;
		
		return *sc2api_textures.find(Texture(opengl_to_sc2api[texture]));
	}
}