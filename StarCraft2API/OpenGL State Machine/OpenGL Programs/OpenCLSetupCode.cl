		struct program_struct program;
		struct vertex_struct vertex;
		__global struct result_struct* result = 0;
		__global float4* result_texcoord = 0;

		program.env = program_env;
		program.local_env = program_local;

		if (vertex_attrib_array)
		{
			for (unsigned int i = 0;i < vertex_render_count;++i)
			{
				struct attrib_info_struct attrib = vertex_attrib_info_array[i];
				
				if (attrib.enabled)
				{
					__global float* base_of_attrib = vertex_attrib_array + attrib.offset + attrib.stride * vertex_indice_array[indice_offset + global_identifier];
					
					bool unsigned_type = (attrib.type_size < 0);
					
					if (unsigned_type)
						attrib.type_size *= -1;
					
					if (attrib.size >= 1)
					{
						vertex.attrib[attrib.index].x = *(base_of_attrib + attrib.type_size * 1);
						
						if (attrib.normalize)
						{
							if (unsigned_type)
								vertex.attrib[attrib.index].x = (vertex.attrib[attrib.index].x)/(256 * attrib.type_size);
							else
								vertex.attrib[attrib.index].x = (vertex.attrib[attrib.index].x * 2 + 1)/(256 * attrib.type_size);
						}
					}
					
					if (attrib.size >= 2)
					{
						vertex.attrib[attrib.index].y = *(base_of_attrib + attrib.type_size * 2);
						
						if (attrib.normalize)
						{
							if (unsigned_type)
								vertex.attrib[attrib.index].y = (vertex.attrib[attrib.index].y)/(256 * attrib.type_size);
							else
								vertex.attrib[attrib.index].y = (vertex.attrib[attrib.index].y * 2 + 1)/(256 * attrib.type_size);
						}
					}
				
					if (attrib.size >= 3)
					{
						vertex.attrib[attrib.index].z = *(base_of_attrib + attrib.type_size * 3);
						
						if (attrib.normalize)
						{
							if (unsigned_type)
								vertex.attrib[attrib.index].z = (vertex.attrib[attrib.index].z)/(256 * attrib.type_size);
							else
								vertex.attrib[attrib.index].z = (vertex.attrib[attrib.index].z * 2 + 1)/(256 * attrib.type_size);
						}
					}
					
					if (attrib.size >= 4)
					{
						vertex.attrib[attrib.index].w = *(base_of_attrib + attrib.type_size * 4);
						
						if (attrib.normalize)
						{
							if (unsigned_type)
								vertex.attrib[attrib.index].w = (vertex.attrib[attrib.index].w)/(256 * attrib.type_size);
							else
								vertex.attrib[attrib.index].w = (vertex.attrib[attrib.index].w * 2 + 1)/(256 * attrib.type_size);
						}
					}
				}
			}
		}
		
		if (result_array)
		{
			result = &result_array[global_identifier];
			
			if (result_texcoord_array)
				result_texcoord = &result_texcoord_array[global_identifier * result_texcoord_max_size];
		}
