
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Shader.h"
#include "stb_image.hpp"
//g++ main.cpp -lGL -lglfw -lGLEW
using namespace std;

const unsigned int WIDTH=600;
const unsigned int HEIGHT=450;
/*
const char* vertexShaderSource="#version 330 core\n"
"layout (location =0) in vec3 aPos;\n"
//        "layout (location=1) in vec3 aColor;\n"
//"out vec3 ourColor;\n"
"void main(){\n"
"    gl_Position= vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
  //      "ourColor=aColor;\n"
"}";
*/
/*const char* fragmentShaderSource="#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 ourColor;\n"
    //    "in vec3 ourColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = ourColor;\n"//vec4(ourColor, 1.0f);\n"
        "} ";
*/
void framebuffer_size_callback(GLFWwindow* window,int width,int height){
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow* window){
    if (glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    cout<<glGetError()<<"  133"<<endl;

    GLFWwindow* window=glfwCreateWindow(WIDTH,HEIGHT,"firstShader",NULL,NULL);
    if (window==NULL){
        cout<<"failed to create glfw window"<<endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    cout<<glGetError()<<"  9"<<endl;
    glewExperimental = GL_TRUE;
    cout<<glGetError()<<"  10"<<endl;//GLEW obtains information on the supported
    // extensions from the graphics driver. Experimental or pre-release drivers,
    // however, might not report every available extension through the standard
    // mechanism, in which case GLEW will report it unsupported. To circumvent
    // this situation, the glewExperimental global switch can be turned on by
    // setting it to GL_TRUE before calling glewInit(), which ensures that all
    // extensions with valid entry points will be exposed.
    //glewInit();
    if (glewInit() != GLEW_OK)
        cout<<"FAILED TO INITIALIZE GLEW\N"<<endl;
    cout<<glGetError()<<"  11"<<endl;
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    cout<<glGetError()<<"  12"<<endl;
    //////////////////////////////////////////////////////////
    Shader ourShader("/home/madina/ClionProjects/shader_1_lesson/vertex",
                     "/home/madina/ClionProjects/shader_1_lesson/fragment");
    /*unsigned int vertexShader,fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);*/
    cout<<glGetError()<<"  13"<<endl;
    ////////////////////////////////////////////////
    float vertices[]={
            0.5f,0.5f,0.0f,     1.0f,0.0f,0.0f, 1.0f,1.0f,
            0.5f,-0.5f,0.0f,    0.0f,1.0f,0.0f, 1.0f,0.0f,
            -0.5f,-0.5f,0.0f,   0.0f,0.0f,1.0f, 0.0f,0.0f,
            -0.5f,0.5f,0.0f,    1.0f,1.0f,0.0f, 0.0f,1.0f
    };
    /*float texCoords[]={
            0.0f,1.0f,
            1.0f,1.0f,
            0.5f,0.0f
    };*/
    unsigned int indices[]={
            0,1,3,
            1,2,3
    };
    unsigned int VBO,VAO,EBO;
    glGenVertexArrays(1,&VAO);
    cout<<glGetError()<<"  133"<<endl;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    cout<<glGetError()<<"  133"<<endl;

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    cout<<glGetError()<<"  133"<<endl;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
    cout<<glGetError()<<"  135"<<endl;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);
    ////////////////////////////////////////////////////
    unsigned int texture1,texture2;
    glGenTextures(1,&texture1);
    glBindTexture(GL_TEXTURE_2D,texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    int w,h,nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data;
    data=stbi_load("/home/madina/ClionProjects/shader_1_lesson/container.jpg",&w,&h,&nrChannels,0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else cout<<"failes to load texture"<<endl;
    stbi_image_free(data);
    glGenTextures(1,&texture2);
    glBindTexture(GL_TEXTURE_2D,texture2);
    /*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    */data=stbi_load("/home/madina/ClionProjects/shader_1_lesson/awesomeface.png",&w,&h,&nrChannels,0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else cout<<"failes to load texture"<<endl;
    stbi_image_free(data);
    ////////////////////////////////////////////////////////////////////
    //glUseProgram(shaderProgram);
    ourShader.use();
    //ourShader.setInt("ourTexture1",0);
    glUniform1i(glGetUniformLocation(ourShader.ID, "ourTexture1"), 0);
    //glUniform1i(glGetUniformLocation(ourShader.ID,"texture2"), 1);
    ourShader.setInt("ourTexture2",1);

    while(!glfwWindowShouldClose(window)){
        processInput(window);

        glClearColor(0.2,0.4,0.4,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
/*
        //float timevalue=glfwGetTime();
        //float greenValue=sin(timevalue)/2.0f+0.5f;
        //float offset =-0.3f+greenValue;
        //ourShader.setFloat("offset",offset);
        //ourShader.setvec4("ourColor",0.0f,greenValue,0.0f,1.0f);
        //int vertexColorLocation=glGetUniformLocation(shaderProgram,"ourColor");
        //glUniform4f(vertexColorLocation,0.0f,greenValue,0.0f,1.0f);
        //ourShader.setInt("ourTexture",0);
        //glBindVertexArray(VAO);
        //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        */
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,texture2);

        ourShader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1,&EBO);

    cout << "Hello, World!" << endl;
    glfwTerminate();
    return 0;
}