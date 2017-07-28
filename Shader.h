//
// Created by madina on 21.07.17.
//

#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Shader
{
public:
    unsigned int ID;
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    void use();
    void setBool(const string &name,bool value) const;
    void setInt(const string &name,int value) const;
    void setFloat(const string &name,float value) const;
    void setvec4(const string name, float r,float g,float b,float a) const;
};

#endif //SHADER_H
