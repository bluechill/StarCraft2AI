#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cctype>

using namespace std;

int main()
{
	ifstream gl("/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers/gliDispatch.h");

	if (!gl.is_open())
	{
		cout << "Failed to open gliDispatch.h" << endl;
		return 1;
	}
	
	std::string line;
	
	struct function_type
	{
		string type, function_name;
		string parameters;
		string parameter_names;
	};
	
	vector<function_type> functions;
	
	while (getline(gl, line))
	{
		if (line.size() == 0 ||
			line[0] == '/' ||
			line[0] == '{' ||
			line[0] == '}' ||
			line[0] == '*' ||
			line == "\t")
			continue;
		
		// 	void (*accum)(GLIContext ctx, GLenum op, GLfloat value);
		
		string type, function_name, parameters, parameter_names;
		
		int i = 0, start = 0;
		
		for(i = 0;!isalpha(line[i]);++i);
		
		start = i;
		for(;isalpha(line[i]);++i);
		
		type = line.substr(start, i-start);
		
		if (type != "void" && (type[0] != 'G' && type[1] != 'L'))
			continue;
		
		if (type == "GL")
			continue;
		
		for(;line[i] != '(';++i);
		
		++i; // skip (
		++i; // skip *
		
		start = i;
		for(;line[i] != ')';++i);
		
		function_name = line.substr(start, i - start);
		
		++i; // skip )
		
		if (line[i] == ' ')
			++i; // skip space
		
		++i; // skip (
		
		start = i;
		for(;line[i] != ')';++i);
		
		parameters = line.substr(start, i-start);
		
		istringstream iss(parameters);
		
		vector<string> tokens{	istream_iterator<string>{iss},
								istream_iterator<string>{}};
		
		for (int i = 1;i < tokens.size();++i)
		{
			if (tokens[i].back() != ',' && (i+1) != tokens.size())
				continue;
			
			while (tokens[i].front() == '*')
				tokens[i] = tokens[i].substr(1);
			
			parameter_names += tokens[i];
			parameter_names += " ";
		}
		
		parameter_names.pop_back();
		
		// Generate the override output
		functions.push_back({type, function_name, parameters, parameter_names});
	}
	
	// 	static CGLContextObj (*CGLGetCurrentContext_reenter)();
	cout << "#include <OpenGL/OpenGL.h>" << endl;
	cout << "#include <OpenGL/CGLTypes.h>" << endl;
	cout << "#include <OpenGL/CGLContext.h>" << endl;
	cout << "#include <OpenGL/gliContext.h>" << endl;
	cout << endl;
	cout << "#include <syslog.h>" << endl;
	cout << "#include <cstdio>" << endl;
	cout << "#include <dlfcn.h>" << endl;
	cout << endl;
	cout << "#include \"mach_override.h\"" << endl;
	cout << endl;
	
	cout << "void OverrideCGLGetContext()" << endl;
	cout << "{" << endl;
	
	cout << '\t' << "static FILE* output = fopen(\"/Users/bluechill/Developer/OpenGLInjector/OpenGLFileLogger/OpenGLFileLogger/OpenGLLog.log\", \"w\");" << endl;
	cout << '\t' << "static CGLContextObj (*CGLGetCurrentContext_reenter)();" << endl;
	cout << '\t' << "static bool overriden = false;" << endl;
	
	for (function_type& f : functions)
		cout << '\t' << "static " << f.type << " (*" << f.function_name << "_reenter)(" << f.parameters << ");" << endl;
	
	cout << endl;
	cout << '\t' << "struct replacement" << endl;
	cout << '\t' << "{" << endl;
	
	for (function_type& f : functions)
	{
		cout << '\t' << '\t' << "static " << f.type << " " << f.function_name << "_replacement(" << f.parameters << ")" << endl;
		cout << '\t' << '\t' << "{" << endl;
		cout << '\t' << '\t' << '\t' << "fprintf(output, \"OpenGLFileLogger: " << f.function_name << " called.\\n\");" << endl;
		cout << '\t' << '\t' << '\t' << endl;
		cout << '\t' << '\t' << '\t' << "return " << f.function_name << "_reenter(" << f.parameter_names << ");" << endl;
		cout << '\t' << '\t' << "}" << endl;
		cout << '\t' << '\t' << endl;
	}
	
	cout << '\t' << '\t'<< "static CGLContextObj CGLGetCurrentContext_replacement(void)" << endl;
	cout << '\t' << '\t'<< "{" << endl;
	cout << '\t' << '\t'<< '\t' << "CGLContextObj obj = CGLGetCurrentContext_reenter();" << endl;
	cout << '\t' << '\t'<< '\t' << "syslog(LOG_NOTICE, \"OpenGLFileLogger: Found Context: %p\", obj);" << endl;
	cout << '\t' << '\t'<< '\t' << "if (!overriden)" << endl;
	cout << '\t' << '\t'<< '\t' << "{" << endl;
	cout << '\t' << '\t'<< '\t' << '\t' << "extern void suspend_all_threads();" << endl;
	cout << '\t' << '\t'<< '\t' << '\t' << "suspend_all_threads();" << endl;
	cout << endl;
	
	for (function_type& f : functions)
	{
		cout << '\t' << '\t' << '\t' << '\t' << "if (obj->disp." << f.function_name << ")" << endl;
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << "mach_override_ptr((void*)obj->disp." << f.function_name << ", (void*)" << f.function_name << "_replacement, (void**)&" << f.function_name << "_reenter);" << endl;
		cout << endl;
	}
	
	cout << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "overriden = true;" << endl;
	cout << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "extern void unsuspend_all_threads();" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << "unsuspend_all_threads();" << endl;
	cout << '\t' << '\t' << '\t' << "}" << endl;
	cout << '\t' << '\t' << endl;
	cout << '\t' << '\t' << '\t' << "return obj;" << endl;
	cout << '\t' << '\t' << "}" << endl;
	cout << '\t' << "};" << endl;
	cout << endl;
	
	cout << '\t' << "void* handle = dlopen(\"/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib\", RTLD_NOW);" << endl;
	cout << endl;
	cout << '\t' << "if (!handle)" << endl;
	cout << '\t' << "	syslog(LOG_ERR, \"Failed to open libGL.  %s\", dlerror());" << endl;
	cout << endl;
	cout << '\t' << "void* opengl_function = dlsym(handle, \"CGLGetCurrentContext\");" << endl;
	cout << endl;
	cout << '\t' << "if (!opengl_function)" << endl;
	cout << '\t' << "	syslog(LOG_ERR, \"Failed to find _CGLGetCurrentContext.  %s\", dlerror());" << endl;
	cout << endl;
	cout << '\t' << "mach_error_t error = mach_override_ptr((void*)opengl_function, (void*)replacement::CGLGetCurrentContext_replacement, (void**)&CGLGetCurrentContext_reenter);" << endl;
	cout << endl;
	cout << '\t' << "if (error)" << endl;
	cout << '\t' << "	syslog(LOG_ERR, \"OpenGLFileLogger: Error overriding OpenGL call 'CGLGetCurrentContext' %i\", error);" << endl;
	cout << endl;
	cout << '\t' << "dlclose(handle);" << endl;
	cout << "}" << endl;
	
	return 0;
}
