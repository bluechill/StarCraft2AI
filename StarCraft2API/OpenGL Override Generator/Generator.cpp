#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cctype>

using namespace std;

int main(int argc, char** argv)
{
	ostream* out = &cout;
	ofstream file;
	
	file.open("/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/Loader/OpenGLOverrider.cpp");
		
	if (file.is_open())
		out = &file;
	
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
		
		vector<pair<string, string>> parameter_vector;
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
		
		pair<string, string> parameter;
		vector<pair<string, string>> parameter_vector;
		for (int i = 0;i < tokens.size();++i)
		{
			if (tokens[i] == "const")
				parameter.first += tokens[i];
			else if (tokens[i].back() != ',' && (i+1) != tokens.size())
			{
				if (parameter.first.size() > 0)
					parameter.first += " ";
				
				parameter.first += tokens[i];
			}
			else
			{
				while (tokens[i].front() == '*')
				{
					tokens[i] = tokens[i].substr(1);
					parameter.first += '*';
				}
				
				if ((i+1) != tokens.size() && tokens[i].back() != ',')
					tokens[i].pop_back();
				
				if (tokens[i].back() == ',')
					tokens[i].pop_back();
				
				parameter.second = tokens[i];
				
				parameter_names += parameter.second + ", ";
				parameter_vector.push_back(parameter);
				
				parameter.first = "";
				parameter.second = "";
			}
		}
		
		parameter_names.pop_back();
		parameter_names.pop_back();
		
		// Generate the override output
		functions.push_back({type, function_name, parameters, parameter_names, parameter_vector});
	}
	
	// 	static CGLContextObj (*CGLGetCurrentContext_reenter)();
	*out << "#include <OpenGL/OpenGL.h>" << endl;
	*out << "#include <OpenGL/CGLTypes.h>" << endl;
	*out << "#include <OpenGL/CGLContext.h>" << endl;
	*out << "#include <OpenGL/gliContext.h>" << endl;
	*out << endl;
	*out << "#include <syslog.h>" << endl;
	*out << "#include <cstdio>" << endl;
	*out << "#include <dlfcn.h>" << endl;
	*out << endl;
	*out << "#include <mutex>" << endl;
	*out << "#include <string>" << endl;
	*out << "#include <map>" << endl;
	*out << endl;
	*out << "#include \"mach_override.h\"" << endl;
	*out << endl;
	*out << "extern std::string GLenumToString(GLenum value);" << endl;
	*out << "#include \"OpenGL State Machine.h\"" << endl;
	*out << endl;
	*out << "using namespace std;" << endl;
	*out << endl;
	
	*out << endl;
	
	// Logging
	*out << "static mutex file_mutex;" << endl;
	*out << "static FILE* output = fopen(\"/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/SC2 Info/SC2Log.log\", \"w\");" << endl;

	*out << "static void file_log(const char* message, ...)" << endl;
	*out << "{" << endl;
	*out << '\t' << "va_list list;" << endl;
	*out << '\t' << "va_start(list, message);" << endl;
	*out << '\t' << endl;
	*out << '\t' << "std::string cpp_message = message;" << endl;
	*out << '\t' << "cpp_message.insert(0, \"SC2API: \");" << endl;
	*out << '\t' << endl;
	*out << '\t' << "file_mutex.lock();" << endl;
	*out << '\t' << "vfprintf(output, cpp_message.c_str(), list);" << endl;
	*out << '\t' << "file_mutex.unlock();" << endl;
	*out << "}" << endl;
	
	*out << endl;
	
	*out << "static void log(int priority, const char* message, ...)" << endl;
	*out << "{" << endl;
	*out << '\t' << "va_list list;" << endl;
	*out << '\t' << "va_start(list, message);" << endl;
	*out << '\t' << endl;
	*out << '\t' << "std::string cpp_message = message;" << endl;
	*out << '\t' << "cpp_message.insert(0, \"SC2API: \");" << endl;
	*out << '\t' << endl;
	*out << '\t' << "vsyslog(priority, cpp_message.c_str(), list);" << endl;
	*out << "}" << endl;
	
	*out << endl;
	
	*out << "static void HandleCGLGetCurrentContext(CGLContextObj obj)" << endl;
	*out << "{" << endl;
	*out << '\t' << "static map<GLIContext, CGLContextObj> overriden_ctx;" << endl;
	*out << '\t' << "" << endl;
	*out << '\t' << "if (obj && overriden_ctx.find(obj->rend) == overriden_ctx.end())" << endl;
	*out << '\t' << "{" << endl;
	*out << '\t' << '\t' << "overriden_ctx[obj->rend] = obj;" << endl;
	*out << '\t'<< '\t' << "extern void suspend_all_threads();" << endl;
	*out << '\t'<< '\t' << "suspend_all_threads();" << endl;
	*out << '\t' << '\t' << "kern_return_t err;" << endl;
	*out << '\t' << '\t' << "" << endl;
	
	for (function_type& f : functions)
	{
		*out << '\t' << '\t' << "MACH_OVERRIDE(" << f.type << "," << f.function_name << ",(" << f.parameters << "), err ) {" << endl;
		*out << '\t' << '\t' << '\t' << "file_log(\"" << f.function_name << " called:";
		
		for (pair<string,string>& p : f.parameter_vector)
		{
			*out << " " << p.second << " (" << p.first << " : ";
			
			if (p.first == "GLenum")
				*out << "%s";
			else if (p.first.find("*") != string::npos || p.first == "GLIContext" || p.first == "GLhandleARB" || p.first == "GLsizeiptrARB" || p.first == "GLintptrARB" || p.first == "GLintptr" || p.first == "GLsizeiptr" || p.first == "GLsync")
				*out << "%p";
			else if (p.first == "GLfloat" || p.first == "GLclampf" || p.first == "GLclampd" || p.first == "GLdouble")
				*out << "%f";
			else if (p.first == "GLint" || p.first == "GLsizei" || p.first == "GLbyte" || p.first == "GLshort" || p.first == "GLboolean")
				*out << "%i";
			else if (p.first == "GLuint" || p.first == "GLbitfield" || p.first == "GLubyte" || p.first == "GLushort" || p.first == "GLuint64")
				*out << "%u";
			else
				*out << "UNKNOWN";
			
			*out << ")";
		}
		
		*out << "\\n\", ";
		
		for (int i = 0;i < f.parameter_vector.size();++i)
		{
			if (f.parameter_vector[i].first != "GLenum")
				*out << f.parameter_vector[i].second;
			else
				*out << "GLenumToString(" << f.parameter_vector[i].second << ").c_str()";
			
			if ((i+1) != f.parameter_vector.size())
				*out << ", ";
		}
		
		*out << ");" << endl;
		
		if (f.type != "void" && f.type != "GLvoid")
		{
			*out << '\t' << '\t' << '\t' << f.type << " result = " << f.function_name << "_reenter(" << f.parameter_names << ");" << endl;
			
			if (f.function_name.find("bind_") != string::npos || f.function_name.find("draw_") != string::npos || f.function_name.find("active_") == 0)
				*out << '\t' << '\t' << '\t' << "OpenGL::StateMachine::Shared." << f.function_name << "(" << f.parameter_names << ", result" << ");" << endl;
			
			*out << '\t' << '\t' << '\t' << "return result;" << endl;
		}
		else
		{
			if (f.function_name.find("bind_") != string::npos || f.function_name.find("draw_") != string::npos || f.function_name.find("active_") == 0)
				*out << '\t' << '\t' << '\t' << "OpenGL::StateMachine::Shared." << f.function_name << "(" << f.parameter_names << ");" << endl;
			
			*out << '\t' << '\t' << '\t' << "return " << f.function_name << "_reenter(" << f.parameter_names << ");" << endl;
		}
		
		*out << '\t' << '\t' << "} END_MACH_OVERRIDE_PTR(" << f.function_name << ", obj->disp." << f.function_name << ");" << endl << endl;
		
		*out << '\t' << '\t' << "if (err)" << endl;
		*out << '\t' << '\t' << '\t' << "log(LOG_ERR, \"Failed to override " << f.function_name << ": %i\", err);" << endl << endl;
	}
	
	*out << '\t'<< '\t' << "extern void unsuspend_all_threads();" << endl;
	*out << '\t'<< '\t' << "unsuspend_all_threads();" << endl;
	*out << '\t' << "}" << endl;
	*out << "}" << endl << endl;
	
	// CGLGetContext
	
	*out << endl;
	*out << "void OverrideCGLGetContext()" << endl;
	*out << "{" << endl;
	
	*out << '\t' << "void* handle = dlopen(\"/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib\", RTLD_NOW);" << endl;
	*out << endl;
	*out << '\t' << "if (!handle)" << endl;
	*out << '\t' << "	log(LOG_ERR, \"Failed to open libGL.  %s\", dlerror());" << endl;
	*out << endl;
	*out << '\t' << "void* opengl_function = dlsym(handle, \"CGLGetCurrentContext\");" << endl;
	*out << endl;
	*out << '\t' << "if (!opengl_function)" << endl;
	*out << '\t' << "	log(LOG_ERR, \"Failed to find _CGLGetCurrentContext.  %s\", dlerror());" << endl;
	*out << endl;
	
	*out << '\t' << "kern_return_t err;" << endl;
	*out << '\t' << "MACH_OVERRIDE( CGLContextObj, CGLGetCurrentContext, (void), err ) {" << endl;
	*out << '\t' << '\t' << "CGLContextObj obj = CGLGetCurrentContext_reenter();" << endl;
	*out << '\t' << '\t' << "HandleCGLGetCurrentContext(obj);" << endl;
	*out << '\t' << '\t' << "return obj;" << endl;
	*out << '\t' << "} END_MACH_OVERRIDE_PTR(CGLGetCurrentContext, opengl_function);" << endl;
	
	*out << endl;
	*out << '\t' << "if (err)" << endl;
	*out << '\t' << "	log(LOG_ERR, \"OpenGLFileLogger: Error overriding OpenGL call 'CGLGetCurrentContext' %i\", err);" << endl;
	*out << endl;
	*out << '\t' << "dlclose(handle);" << endl;
	*out << "}" << endl;
	
	return 0;
}
