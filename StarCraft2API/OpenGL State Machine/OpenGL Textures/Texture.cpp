//
//  Texture.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "Texture.h"

#include <string>

namespace OpenGL
{
	Texture::Texture()
	: hash(0), classification("Empty Texture")
	{}
	
	Texture::Texture(std::string hash, std::string classification)
	{
		try
		{
			this->hash = std::stoul(hash);
		}
		catch (std::exception& e)
		{
			this->hash = 0;
		}
		
		this->classification = classification;
	}
	
	Texture::Texture(unsigned int hash)
	{
		this->hash = hash;
	}
	
	Texture::~Texture()
	{}
	
	unsigned int Texture::get_hash() const
	{
		return hash;
	}
	
	std::string Texture::get_classification() const
	{
		return classification;
	}
	
	bool Texture::operator==(const Texture& other) const
	{
		return other.hash == this->hash;
	}
}
