#include "Shader.h"
#include <iostream>

Shader::Shader()
{

}

Shader::~Shader()
{
	glDeleteProgram(m_program);
}

bool Shader::Init(const char* vs_fName, const char* fs_fName)
{
	//load the shaders
	m_vs = CreateShader(vs_fName, GL_VERTEX_SHADER);
	m_fs = CreateShader(fs_fName, GL_FRAGMENT_SHADER);
	if (m_vs == 0 || m_fs == 0)
	{
		return false;
	}

	//create the program to link the shaders
	GLint link_ok = GL_FALSE;
	m_program = glCreateProgram();
	glAttachShader(m_program, m_vs);
	glAttachShader(m_program, m_fs);
	glLinkProgram(m_program);
	glGetProgramiv(m_program, GL_LINK_STATUS, &link_ok);
	if (!link_ok)
	{
		std::cerr <<  "shader link error";
		PrintError(m_program);
		return false;
	}

	if(!InitAttributes())
	{
	  std::cerr << "failed to create attributes\n";
	  return false;
	}

	m_u_transform = glGetUniformLocation(m_program, "transform");
	if(m_u_transform == -1)
	{
	  std::cerr << "Couldn't bind transform" << std::endl;
	  return false;
	}
	return true;	
}

void Shader::SendParameters(glm::mat4 transformMatrix)
{
  glUniformMatrix4fv(m_u_transform, 1, GL_FALSE, glm::value_ptr(transformMatrix));
}

GLuint Shader::CreateShader(const char* fName, GLenum type)
{
	const GLchar* source = LoadShader(fName);
	if (source == NULL)
	{
		//std::cerr << "Error opening " << fName << ": " << SDL_GetError() << std::endl;
		return 0;
	}
	//create the shader
	GLuint result = glCreateShader(type);
	const GLchar* sources[] = {
#ifdef GL_ES_VERSION_2_0
		"#version 100\n"
#else
		"#version 120\n"
#endif
		, source };
	glShaderSource(result, 2, sources, NULL);
	delete source;

	//try to compile the shader
	glCompileShader(result);
	GLint compile_ok = GL_FALSE;
	glGetShaderiv(result, GL_COMPILE_STATUS, &compile_ok);
	if (compile_ok == GL_FALSE)
	{
		std::cerr << fName << ": shader compile error";
		PrintError(result);
		glDeleteShader(result);
	}

	return result;
}

const char* Shader::LoadShader(const char* fName)
{
	//try to open the file
	/*SDL_RWops* rw = SDL_RWFromFile(fName, "rb");
	if (rw == NULL)
	{
		return NULL;
	}

	//set up the read buffer
	Sint64 readSize = SDL_RWsize(rw);
	char* result = new char[readSize + 1];

	Sint64 readTotal = 0;
	Sint64 read = 1;

	//read in the data
	char* buffer = result;
	while (readTotal < readSize && read != 0)
	{
		read = SDL_RWread(rw, buffer, 1, (readSize - readTotal));
		readTotal += read;
		buffer += read;
	};

	//close the file and check if the reading was successful
	SDL_RWclose(rw);
	if (readTotal != readSize)
	{
		delete result;
		return NULL;
	}*/

	std::ifstream file;
	file.open(fName);

	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	
	return content.data();//c_str();
}

void Shader::PrintError(GLuint object)
{
	GLint log_length = 0;
	if (glIsShader(object)) 
	{
		glGetShaderiv(object, GL_INFO_LOG_LENGTH, &log_length);
	}
	else if (glIsProgram(object)) 
	{
		glGetProgramiv(object, GL_INFO_LOG_LENGTH, &log_length);
	}
	else 
	{
		std::cerr << "printlog: Not a shader or a program" << std::endl;
		return;
	}

	char* log = (char*)malloc(log_length);

	if (glIsShader(object))
	{
		glGetShaderInfoLog(object, log_length, NULL, log);
	}
	else if (glIsProgram(object))
	{
		glGetProgramInfoLog(object, log_length, NULL, log);
	}
		

	std::cerr << log;
	delete log;
}

 bool Shader::InitAttributes()
 {
   m_attributes = new GLuint[3];

   //2D coordinate
   /*m_attributes[0] = glGetAttribLocation(m_program, "coord2d");
   if(m_attributes[0] == -1)
   {
     std::cerr << "failed to create coord2d" << std::endl;
     return false;
   }*/

   //3D coordinate
   m_attributes[ATTRIBUTE_COORD3D] = glGetAttribLocation(m_program, "coord3d");
   if(m_attributes[ATTRIBUTE_COORD3D] == -1)
   {
     std::cerr << "failed to create coord3d" << std::endl;
     return false;
   }
   
   //rgb colour
   m_attributes[ATTRIBUTE_RGB] = glGetAttribLocation(m_program, "colour_rgb");
   if(m_attributes[ATTRIBUTE_RGB] == -1)
   {
     std::cerr << "failed to create colour_rgb\n" << std::endl;
     return false;
   }
   
   return true;
 }
