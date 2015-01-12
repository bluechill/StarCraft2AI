//
//  TextureDatabase.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__TextureDatabase__
#define __StarCraft2API__TextureDatabase__

#include "Texture.h"

#include <OpenGL/OpenGL.h>

#include <unordered_set>
#include <unordered_map>

#include "rapidxml.hpp"

namespace OpenGL
{
	class TextureDatabase
	{
	public:
		TextureDatabase();
		
		bool has_texture(GLuint texture);
		void create_texture(GLuint texture);
		const Texture& get_texture(GLuint texture);
		
		Texture empty_texture;
		
	private:
		bool setup;
		void setup_db();
		
		std::unordered_set<GLuint> opengl_textures;
		std::unordered_set<Texture> sc2api_textures;
		std::unordered_map<GLuint, unsigned int> opengl_to_sc2api;
		
		rapidxml::xml_document<> db_xml;
	};
}

#endif /* defined(__StarCraft2API__TextureDatabase__) */
