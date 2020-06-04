
#include <string>
#include <map>
#include <mutex>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "sol2/sol.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

const int MAX_SIMUL = 32,
          FPS = 60,
          MAX_ATTACHED_CHAR = 2,
          P1P3_DIST = 25,
          MP3_SAMPLE_RATE = 44100;

struct System
{
    int32_t randSeed;
    int32_t sccrect[4];
    float widthScale, heightScale;
    GLFWwindow *window;
    bool gameEnd, frameSkip;
    struct redrawWait{/*TODO: Implement nextTime and lastDraw*/};
    int32_t time;
    int32_t brightness;
    int32_t roundTime;
    float lifeMul;
    float singleVSTeamLife;
    float turnsRecoveryBase;
    float turnsRecoveryBonus;
    float lifeBarFontScale;
    //TODO: IMPLEMENT Font *font;
    std::string debugScript;
    bool debugDraw;
    //Mixer mixer
    //BGM bgm
    ALCcontext *ALcontext;
    //[audioLenOut * 2]int16 nullSndBuffer->translate this from golang to c++
    //Sounds sounds;
    //PalFX allPalFX, bgPalFX;
    //LifeBar lifeBar;
    //Select select
    //TODO: Wrap all the key codes like here: https://godoc.org/github.com/go-gl/glfw/v3.1/glfw#Key, and pass throgh a map-> std::map<GLFWKey, bool> keyState;
    //NetInput *netInput;
    //FileInput *fileInput;
    //[MaxSimul*2 + MaxAttachedChar]AiInput aiInput;
    //KeyConfig[] keyboardConfig;
    //KeyConfig[] joystickConfig;
    //[MaxSimul*2 + MaxAttachedChar]float32 com;
    bool autoLevel;
    int home;
    int32_t gameTime;
    int32_t match;
    //[MaxSimul*2 + MaxAttachedChar]int inputRemap;
    std::string listenPort;
    int32_t round;
    int32_t intro;
    int winTeam;
    //WinType[2] winType;
    int32_t matchesWon[2], wins[2];
    int32_t roundsExisted[2];
    int32_t matchDraws;
    //Loader loader;
    //[MaxSimul*2 + MaxAttachedChar][]*Char chars;
    //CharList charList;
    //[MaxSimul*2 + MaxAttachedChar]CharGlobalInfo cgi
    //TeamMode[2] teamMode;
    int32_t numSimul[2], numTurns[2];
    bool esc;
    
};