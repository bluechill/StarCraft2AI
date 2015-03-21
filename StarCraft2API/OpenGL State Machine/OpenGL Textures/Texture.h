//
//  Texture.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__Texture__
#define __StarCraft2API__Texture__

#include <string>

namespace OpenGL
{
	class Texture
	{
	public:
		Texture();
		
		Texture(std::string hash, std::string classification);
		Texture(unsigned int hash);
		~Texture();
		
		unsigned int get_hash() const;
		std::string get_classification() const;
		
		bool operator==(const Texture& other) const;
		
	private:
		std::string classification;
		unsigned int hash;
	};
}

namespace std
{
	template<> struct hash<OpenGL::Texture>
	{
		size_t operator()(const OpenGL::Texture& t)
		{
			return t.get_hash();
		}
	};
}

#endif /* defined(__StarCraft2API__Texture__) */
