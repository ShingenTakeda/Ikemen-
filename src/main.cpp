#include <iostream>
#include <assert.h>
#include <map> //-<take this out when you include System.hpp
//#include "System.hpp" -> Include this to see your sins 
#include <GLFW/glfw3.h>

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

    struct JoystickConfig
    {
        int joystick;
        //buttons []interface{} -> see how to do this in c++
    };

    struct KeyConfig
    {
        int keys;
        //buttons []interface{} -> see how to do this in c++
    };

    struct tmp
    {
        bool AIRamping;
        bool AIRandomColor;
        bool autoGuard;
        int32_t comboExtraFrameWindow;
        std::string commonAIR;
        std::string commonCMD;
        std::string commonConst;
        std::string commonScore;
        std::string commonTag;
        float controllerSensitivity;
        int credits;
        bool debugMode;
        bool debugKeys;
        int difficulty;
        bool fullScreen;
        int32_t gameWidth;
        int32_t gameHeight;
        float gameSpeed;
        std::map<std::string, std::string> IP;//->See if you will need this in GGPO
        float lifeBarFontScale;
        float lifeMul;
        std::string listenPort;
        int32_t loccalCoordScalingType;
        int32_t maxAfterImage;
        int32_t maxDrawGame;
        int maxPlayerPojectile;
        std::string motif;
        bool MSAA;
        float multAttackToLifePower;
        float mulGetHitToLifePower;
        float superTargetDefence;
        int numSimul[2];
        int numTag[2];
        int numTurns[2];
        int32_t postProcessingImageShader;
        bool preloadingBig;
        bool preloadingSmall;
        bool preloadingVersus;
        bool preloadingStage;
        bool quickStart;
        float ratioAttack[4];
        float ratioLife[4];
        int32_t roundsNumSingle;
        int32_t roundsNumTeam;
        int32_t roundTime;
        bool simulLoseKO;
        float singleVSTeamLife;
        std::string system;
        bool tagLoseKO;
        bool teamLifeAdjustment;
        bool teamPowerShare;
        float turnsRecoveryBase;
        float turnsRecoveryBonus;
        int volumeBGM;
        int volumeMaster;
        int volumeSFX;
        std::string windowTitle;
        float xInputTriggerSensitivity;
        bool zoomActive;
        float zoomMax;
        float zoomMin;
        float zoomSpeed;

        //Joystick struct
        JoystickConfig joystickConfig;//-> in golang this is a slice of a struct see how to adapt this
        KeyConfig keyConfig;//-> in golang this is a slice of a struct see how to adapt this

        /*
        //Structs can only have ONE flexible array, see how to fix these
        std::string externalShaders[];
        std::string windowIconLocation[];
        */
    };

    return 0;
}