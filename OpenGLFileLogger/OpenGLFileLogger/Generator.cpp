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
//	for (int i = 0;i < 2377;++i)
//		getline(gl, line);
	
	cout << "#include \"OpenGLLogger.h\"" << endl;
	cout << "#include <OpenGL/gliDispatch.h>" << endl;
	cout << "#include <syslog.h>" << endl;
	cout << "#include \"mach_override.h\"" << endl;
	cout << endl;
	cout << "extern OpenGLLogger logger;" << endl;
	cout << endl;
	cout << "void OverrideOpenGL()" << endl;
	cout << "{" << endl;
	cout << '\t' << "kern_return_t err;" << endl;
	cout << endl;
	
	while (getline(gl, line))
	{
		if (line.size() == 0)
			continue;
		
		// 	void (*accum)(GLIContext ctx, GLenum op, GLfloat value);
		//	[void function_stuff]
		
		string type, function_name, parameters;
		
		int i, start;
		
		for(i = 0;!isalpha(line[i]);++i);
		
		start = i;
		for(i = 0;isalpha(line[i]);++i);
		
		type = line.substr(start, i);
		
		if (type != "void" && (type[0] != 'G' && type[1] != 'L'))
			continue;
		
		++i; // skip space
		++i; // skip (
		++i; // skip *
		
		start = i;
		for(;line[i] != ')';++i);
		
		
		
		function_name = tokens[1].substr(2, tokens[1].length());
		
		for (;function_name[i] != ')';++i);
		
		function_name.erase(i, function_name.length());
		
		parameters = tokens[1].substr(2 + function_name.length() + 3, tokens[1].length());
		parameters.erase(parameters.size()-2, 2);
		
		// Override output
		cout << '\t' << "MACH_OVERRIDE(" << type << ", " << function_name << ", " << parameters << ", err)" << endl;
		cout << '\t' << "{" << endl;
		cout << '\t' << '\t' << "logger." << function_name << "(" << parameter_names << ");" << endl;
		cout << endl;
		
		if (type == "void")
			cout << '\t' << '\t' << function_name << "_reenter(" << parameter_names << ");" << endl;
		else
			cout << '\t' << '\t' << "return " << function_name << "_reenter(" << parameter_names << ");" << endl;

		cout << '\t' << "} END_MACH_OVERRIDE(" << function_name << ");" << endl;
		
		cout << endl;
		cout << '\t' << "if (err)" << endl;
		cout << '\t' << '\t' << "syslog(LOG_ERR, \"OpenGLFileLogger: Error overriding OpenGL call '" << function_name << "' %i\", err);" << endl;

		cout << endl;
	}
	
	cout << "}" << endl;
	
	return 0;
}
