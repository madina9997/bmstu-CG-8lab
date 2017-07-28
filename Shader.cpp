//
// Created by madina on 21.07.17.
//

#include "Shader.h"
using namespace std;

Shader::Shader(const GLchar *vertexPath, const GLchar *fragmentPath) {
    string vertexCode, fragmentCode;
    ifstream vShaderFile, fShaderFile;
    vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    try{
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        stringstream vShaderStream, fShaderStream;
        vShaderStream<<vShaderFile.rdbuf();
        fShaderStream<<fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vertexCode=vShaderStream.str();
        fragmentCode=fShaderStream.str();
    }
    catch (ifstream::failure e){
        cout<<"erroe file not succesfully read"<<endl;
    }
    const char * vShaderCode = vertexCode.c_str();
    const char * fShaderCode = fragmentCode.c_str();
    ///////////////////////////////////////////////////////////////////

    unsigned int vertex,fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex,1,&vShaderCode,NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);
    if (!success){
        glGetShaderInfoLog(vertex,512,NULL,infoLog);
        cout<<"VERTEX_SHADER_COMPILATION_FAILED"<<infoLog<<endl;
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment,1,&fShaderCode,NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment,GL_COMPILE_STATUS,&success);
    if (!success){
        glGetShaderInfoLog(fragment,512,NULL,infoLog);
        cout<<"FRAGMENT_SHADER_COMPILATION_FAILED"<<infoLog<<endl;
    }

    ID=glCreateProgram();
    glAttachShader(ID,vertex);
    glAttachShader(ID,fragment);
    glLinkProgram(ID);

    glGetProgramiv(ID,GL_LINK_STATUS,&success);
    if (!success){
        glGetProgramInfoLog(ID,512,NULL,infoLog);
        cout<<"LINKING FAILED"<<endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}
void Shader::use() {
    glUseProgram(ID);
}

void Shader::setBool(const string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID,name.c_str()),(int)value);
}

void Shader::setFloat(const string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID,name.c_str()),value);
}

void Shader::setvec4(const string name, float r,float g,float b,float a) const {
    glUniform4f(glGetUniformLocation(ID,name.c_str()),r,g,b,a);
}

void Shader::setInt(const string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID,name.c_str()),value);
}