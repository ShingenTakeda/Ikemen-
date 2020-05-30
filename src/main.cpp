#include <GLFW/glfw3.h>

#include <iostream>
#include <assert.h>
#define SOL_ALL_SAFETIES_ON 1
#include "sol2/sol.hpp"

#include "LuaScript.hpp"


int main(void)
{
    std::cout << "=== opening a state ===" << std::endl;
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::package);
    lua.script("print('Hello from lua')");

    std::cout<<std::endl;

    lua.script_file("test.lua");

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}