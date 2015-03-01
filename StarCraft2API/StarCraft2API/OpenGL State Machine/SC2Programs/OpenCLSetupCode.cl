
		program_struct program;
		vertex_struct vertex;
		result_struct* result;
		
		program.env = program_env;
		program.local_env = program_local;

		if (vertex_array)
		{
			if (vertex_attrib_array)
			{
				for (int i = 0;i < vertex_attrib_index_array_count;++i)
				{
					attrib_info attrib = vertex_attrib_info_array[i];
					
					float* base_of_attrib = vertex_attrib_array + attrib.stride * global_identifier;
					
					if (attrib.size >= 1)
						vertex->attrib[n].x = *(base_of_attrib + attrib.type_size * 1);
					
					if (attrib.size >= 2)
						vertex->attrib[n].y = *(base_of_attrib + attrib.type_size * 2);
				
					if (attrib.size >= 3)
						vertex->attrib[n].z = *(base_of_attrib + attrib.type_size * 3);
					
					if (attrib.size >= 4)
						vertex->attrib[n].w = *(base_of_attrib + attrib.type_size * 4);
				}
			}
		}
		
		if (fragment_array)
		{
			fragment = &fragment_array[global_identifier];
			
			if (fragment_texcoord_array)
				fragment->texcoord = &fragment_texcoord_array[global_identifier * fragment_max_texcoord_size];
		}
		
		if (result_array)
		{
			result = &result_array[global_identifier];
			
			if (result_texcoord_array)
				result->texcoord = &result_texcoord_array[global_identifier * result_texcoord_max_size];
			
			if (result_frag_color_array)
				result->frag_color = &result_frag_color_array[global_identifier * result_frag_color_max_size];
		}
