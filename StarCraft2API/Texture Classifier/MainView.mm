//
//  MainView.m
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#import "MainView.h"

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

#include <vector>
#include <string>
#include <fstream>

#include <syslog.h>

static const std::string texture_db_file = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2DB.xml";
static const std::string texture_db_texture_folder = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2Textures/";

static const std::string texture_db_root = "TextureDatabase";
static const std::string texture_db_texture = "Texture";
static const std::string texture_db_hash = "Hash";
static const std::string texture_db_classification = "Classification";
static const std::string texture_db_classification_unknown = "Unknown";

rapidxml::xml_document<> db_xml;
rapidxml::xml_node<>* root;
rapidxml::xml_node<>* currentNode;

using namespace std;
using namespace rapidxml;


@interface MainView ()

@end

@implementation MainView

@synthesize imageView, classification;

- (void)viewDidLoad {
    [super viewDidLoad];
	
	errno = 0;
	std::ifstream in(texture_db_file, std::ios::in);
	std::vector<string> contents_vec;
	string contents;
	
	if (in)
	{
		for (std::string line; std::getline(in, line); ) {
			contents_vec.push_back(line);
		}
		
		for (string l : contents_vec)
			contents += l + '\n';
	}
	else
		NSLog(@"Failed to open DB file: %s", strerror(errno));
	
	try {
		char* c = db_xml.allocate_string(contents.c_str());
		db_xml.parse<0>(c);
	} catch (rapidxml::parse_error& e) {
		NSLog(@"Failed to parse DB: %s : %s", e.what(), e.where<char>());
	}
	
	root = db_xml.first_node(texture_db_root.c_str());
	
	if (!root)
	{
		char* node_name = db_xml.allocate_string(texture_db_root.c_str());
		xml_node<>* node = db_xml.allocate_node(node_element, node_name);
		db_xml.append_node(node);
		root = node;
	}
	
	TextureObjects = [NSMutableArray array];
	
	for (xml_node<>* node = root->first_node(texture_db_texture.c_str()); node; node = node->next_sibling())
	{
		string hash_str = node->first_attribute(texture_db_hash.c_str())->value();
		string classification = node->first_attribute(texture_db_classification.c_str())->value();
		
		NSMutableDictionary* dict = [NSMutableDictionary dictionary];
		[dict setObject:[NSString stringWithUTF8String:hash_str.c_str()] forKey:@"Hash"];
		[dict setObject:[NSString stringWithUTF8String:classification.c_str()] forKey:@"Classification"];
		
		[TextureObjects addObject:dict];
	}
	
	currentNode = root->first_node(texture_db_texture.c_str());
	
	for (i = 0;i < [TextureObjects count];++i)
	{
		if ([[[TextureObjects objectAtIndex:i] objectForKey:@"Classification"] isEqualToString:@"Unknown"])
			break;
		
		currentNode = currentNode->next_sibling();
	}
	
	if (i != [TextureObjects count])
	{
		self.imageView.image = [[NSImage alloc] initWithContentsOfFile:[NSString stringWithFormat:@"%s/%@.png", texture_db_texture_folder.c_str(), [[TextureObjects objectAtIndex:i] objectForKey:@"Hash"]]];
		[self.classification setStringValue:@"Unknown"];
	}
	else
	{
		self.imageView.image = nil;
		[self.classification setStringValue:@"Done!"];
		self.classification.editable = false;
		self.classification.enabled = false;
	}
	
	in.close();
}

- (void)controlTextDidEndEditing:(NSNotification *)obj
{
	if (i == [TextureObjects count])
	{
		self.imageView.image = nil;
		[self.classification setStringValue:@"Done!"];
		self.classification.editable = false;
		self.classification.enabled = false;
		return;
	}
	
	[[TextureObjects objectAtIndex:i] setObject:classification.stringValue forKey:@"Classification"];
	xml_attribute<>* attr = currentNode->first_attribute(texture_db_classification.c_str());
	
	if (attr)
	{
		char* v = db_xml.allocate_string(classification.stringValue.UTF8String);
		attr->value(v);
		
		std::ofstream out(texture_db_file, std::ios::out | std::ios::trunc);
		
		out << db_xml;
		
		out.close();
	}
	
	for (;i < [TextureObjects count];++i)
	{
		if ([[[TextureObjects objectAtIndex:i] objectForKey:@"Classification"] isEqualToString:@"Unknown"])
			break;
		
		currentNode = currentNode->next_sibling();
	}
	
	if (i != [TextureObjects count])
	{
		self.imageView.image = [[NSImage alloc] initWithContentsOfFile:[NSString stringWithFormat:@"%s/%@.png", texture_db_texture_folder.c_str(), [[TextureObjects objectAtIndex:i] objectForKey:@"Hash"]]];
		[self.classification setStringValue:@"Unknown"];
	}
	else
	{
		self.imageView.image = nil;
		[self.classification setStringValue:@"Done!"];
		self.classification.editable = false;
		self.classification.enabled = false;
	}
}

@end
