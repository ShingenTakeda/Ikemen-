
#include <string>
#include <map>
#include <mutex>
#include <system_error>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "sol2/sol.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

//REMEMBER: refer to system.go and system.ssk on the ikemenGO and ikemen directories
//REMEMBER: uncomment the stuff in the System struc after implementing the functions
//TODO: put the "type"s golang declarations up here somewhere\
//TODO: implement a "channel" type
//OBS:Fuck golang dude

typedef int32_t team_mode;
typedef std::map<std::string,int32_t> wincnt_map[];
typedef int32_t loader_state;

const int n,m;

const int MAX_SIMUL = 32,
          FPS = 60,
          MAX_ATTACHED_CHAR = 2,
          P1P3_DIST = 25,
          MP3_SAMPLE_RATE = 44100;



struct System
{
    int32_t randSeed;
    int32_t sccrect[4];
    int32_t gameWidth, gameHeight;
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
    Select select;
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
    Loader loader;
    //[MaxSimul*2 + MaxAttachedChar][]*Char chars;
    //CharList charList;
    //[MaxSimul*2 + MaxAttachedChar]CharGlobalInfo cgi
    team_mode teamMode[2];
    int32_t numSimul[2], numTurns[2];
    bool esc;
    //sync.Mutex loadMutex;
    bool ignoreMostErrors;
    //[MaxSimul*2 + MaxAttachedChar]StringPool stringPool;
    //ByteCodeStack bcStack, bcVarStack;
    //[]ByteCodeValue bcVar;
    //Char *workingChar;
    //StateByteCode *workingState
    //GlobalSpecialFlag specialFlag;
    int32_t afterImageMax;
    float attack_LifeToPowerMul;
    float getHit_LifeToPowerMul;
    int32_t comboExtraFrameWindow;
    //EnvShake envShake;
    int32_t pause;
    int32_t pauseTime;
    bool pauseBG;
    int32_t pauseCMDBufTime;
    int pausePlayer;
    int32_t super;
    int32_t superTime;
    bool superPauseBG;
    int32_t superEndBufTime;
    int superPlayer;
    bool superDarken;
    //Animation *superAnimation;
    //PalFX superMap;
    float superPos[2];
    float superFacing;
    float superP2DefMul;
    float super_TargetDefence;
    int32_t envCol[3];
    int32_t envColTime;
    bool envCol_Under;
    //[MaxSimul*2 + MaxAttachedChar][]string clipBoardText;
    //Stage *stage;
    int32_t helperMax;
    int32_t nextCharID;
    wincnt_map  *wincnt;//TODO:See if that works correctly with a pointer;
    std::string wincntFileName;
    bool powerShare[2];
    int tickCount;
    int oldTickCount;
    float tickCountF;
    float lastTick;
    float nextAddTime;
    float oldNextAddTime;
    float screenLeft, screenRight;
    float xMin,xMax;
    bool winSkipped;
    bool paused, step;
    bool roundResetFlag;
    bool reloadFlag;
    //[MaxSimul*2 + MaxAttachedChar]bool reloadCharSlot;
    //map[ShortcutKey]*ShortcutScript shortcutScripts;
    float turbo;
    //chan std::string commandLine//TODO:Implement a golang channel equivalent ;
    float drawScale;
    float zoomLag;
    float zoomPosXLag, zoomPosYLag;
    bool enableZoomState;
    float zoomPos[2];
    //Char *debugWC;
    //Camera cam;
    //FinishType finish;
    int32_t waitDown;
    int32_t shutterTime;
    //[MaxSimul*2 + MaxAttachedChar][]Projectile projs;
    //[MaxSimul*2 + MaxAttachedChar][]Explod explods;
    //[MaxSimul*2 + MaxAttachedChar][]int explDrawList;
    //[MaxSimul*2 + MaxAttachedChar][]int topExplDrawList
    int32_t changeStateNest;
    //DrawList sprites;
    //DrawList topSprites;
    //ShadowList shadows;
    //ClsnRect drawC1;
    //ClsnRect drawC2;
    //ClsnRect drawC2SP;
    //ClsnRect drawMTK;
    //ClsnRect drawWH;
    //[MaxSimul*2 + MaxAttachedChar]bool autoGuard;
    bool clsnDraw;
    float accel;
    bool statusDraw;
    //Sprite clsnSpr;
    //channel this function->void MainThreadTask();
    int maxExpld;
    uint32_t workpal;
    int playerProjectileMax;
    //Get a logger here->Logger *errLog;
    //chan bool audioClose;
    bool noMusic;
    //ByteCodeExp workBe[];
    bool lifeadjustment;
    bool simulLoseKO;
    bool tagLoseKO;
    bool fullscreen;
    bool allowDebugKeys;
    std::string commonAir;
    std::string commonCmd;
    //GLFWKey keyInput;
    std::string keyString;
    int32_t timerCount[];
    std::map<std::string, std::string> cmdFlags;
    int masterVolume;
    int wavVolume;
    int bgmVolume;
    bool audioDucking;
    std::string windowTitle;

    float controllerStickSensitivity;
    float xInputTriggerSensitivity;

    //Local coordinate screenpack
    double luaSpriteScale;
    float luaSmallPortraitSprite;
    float luaBigProtraitSprite;
    double luaSpriteOffsetX;

    float lifeBarScale;
    float lifeBarOffsetX;
    float lifebarPortraitScale;
    int32_t localCoordScalingType;

    //Shader variables
    uint32_t postProcessingShader;
    bool multiSamplingAntiAlliasing;//->MSAA

    //External shader variables
    std::string externalShaderList[];
    std::string externalShaderNames[];
    std::string externalShaders[];//Remember to make this array dinamic

    //Window icon
    //Image windowMainIcon[]
    std::string windowMainIconLocation[];

    std::string gameMode;
    int32_t demoTime;
    int32_t frameCounter;
    std::string motifDir;
    int captureNum;
    int challenger;
    //RoundType roundType[];
    //[MaxSimul*2 + MaxAttachedChar]OverrideCharData ocd;
    bool allowBGM;
    //[MaxSimul*2 + MaxAttachedChar]int32 ratioLevel;//->Try to change this to a CapcomvSNK 2 style and maybe a skullgirls kinda of thing
    int32_t timerStart;
    int32_t timerRounds[];
    float scoreStart[2];
    float scoreRounds[][2];
    sol::state *matchData;
    float matchPos[8];
    MatchClearance matchClearance[2];
    int32_t consecutiveWins[2];
    std::string commonConst;
    std::string commonScore;
    std::string commonTag;
    float gameSpeed;
    Preloading preloading;
}sys;

struct OverrideCharData
{
    int32_t power;
    int32_t life;
    int32_t lifeMax;
    float lifeRatio;
    float attackRatio;
};

struct MatchClearance
{
    bool helpers;
    bool sound;
    bool projectiles;
    bool explodes;
};

struct Preloading
{
    bool small;
    bool big;
    bool versus;
    bool stage;
};

struct SelectChar
{
    std::string def;
    std::string sprite;
    std::string sound;
    std::string introStoryBoard;
    std::string endStoryBoard;
    int32_t pal[];
    int32_t palDefault[];
    int32_t palKeyMaps[];
    float portraitScale;
    //Sprite sPortrait;
    //Sprite lPortrait;
    //Sprite vsPortrait;
};

struct SelectStage
{
    std::string def;
    std::string name;
    std::string spr;
    std::string attachedCharDef;
    //StageBGM stageBGM[4];
    //Sprite *stagePortrait;
    float portraitScale;
    float xScale;
    float yScale;
};

struct StageBGM
{
    std::string bgMusic;
    int32_t bgmVolume;
    int32_t bgmLoopStart;
    int32_t bgmLoopEnd;
};

struct Select
{
    int columns, rows;
    float cellSize[2];
    float cellScale[2];
    //Sprite *randomSprite;
    float randomSCL;
    SelectChar charList[];
    SelectStage stageList[];
    int curStageNo;
    //->See how to do this: int selected[2][][2];
    int selectedStageNo;
    int16_t sPorTrait[2];
    int16_t vsPortrait[2];
    int16_t stagePortait[2];
    //std::map<std::string, Anim> aPortrait;
    //std::string cDefOverwrite[MaxSimul * 2];
    std::string sDefOverwrite;
    StageBGM stageBGM[5];
};

struct Loader
{
    loader_state state;

    //channel this declaration
    loader_state loadExit;

    //TODO:error is a basic type in golang, try to do the same in c++
    std::system_error err;
};

//If this doesnt work, try to do it with the struct
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int ResetOverrideCharData(System *s)
{
    /*
    //Stuff in ocd is not yet implemented
    for(int i = 0; i < sizeof(s.ocd); i++)
    {
        s.ocd[i] = OverrideCharData
        {
            int power = 0;
            int life = 0;
            int lifeMax = 0;
            float lifeRatio = 1.0;
            float attackRatio = 1.0;
        }
    }
    return //"Something" since golang can deduce the return value
    */
}

void Init(System *s, int w, int h) //*sol::state
{
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //(*s).SetWindowSize(w, h);
    if((*s).window == NULL)
    {
        std::cout<<"Failed to initialize GLFW window";
        glfwTerminate();
        //return -1;//return a failure here;
    }
    else
    {
        if((*s).fullscreen)
        {
            (*s).window = glfwCreateWindow((int)(*s).sccrect[2],
                                            (int)(*s).sccrect[3],
                                            (*s).windowTitle.c_str(), glfwGetPrimaryMonitor(), NULL);
        }
        else
        {
            (*s).window = glfwCreateWindow((int)(*s).sccrect[2],
                                            (int)(*s).sccrect[3],
                                            (*s).windowTitle.c_str(),
                                            NULL,
                                            NULL);
        }
    }

    glfwMakeContextCurrent((*s).window);
    glfwSetFramebufferSizeCallback((*s).window, framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout<<"Failed to initialize GLAD"<<std::endl;
        //return -1;//return a failure here pls
    }

    glEnable(GL_DEPTH_TEST);

    if((*s).postProcessingShader < (int32_t)sizeof((*s).externalShaderList) + 3)
    {
        (*s).postProcessingShader = 0;
    }

    if(sizeof((*s).externalShaderList) > 0)
    {
        (*s).externalShaders == new std::string[n];//->make this multidimensional and maybe change the value
        (*s).externalShaderNames == new std::string[sizeof((*s).externalShaderList)];
        
        &(*s).externalShaders[1] == new std::string[sizeof((*s).externalShaderList)];
        &(*s).externalShaders[2] == new std::string[sizeof((*s).externalShaderList)];

        /*
        //Iterate through this the "C++11" way
        //TODO:Implement a "Strings" function
        for(ShaderLocation i; i  < sizeof((*s).externalShaderLocation); i++)
        {
            ShaderLocation = Strings.Replace(shaderLocation, "\\", "/", -1);
            SplitDir = Strings.Split(shaderLocation, "/")

            //Load vert shader
            ->Make a Shader loader function
            //Load frag shaders

            //TODO:Geometry and other shader types
        }
        */
    }

    //Initialize the render
    //RenderInit()

    //Initialize sound
    //(*s).audioOpen();

    //int sr = beep.SampleRate(MP3_SAMPLE_RATE);
    //Speaker.Init(sr, sr.N(time.Second/10))
    sol::state l;
    //Implement a stack trace for lua and declare it here
    l.open_libraries();

    /*
    for(int i = 0; i < sizeof(InputMap); i++)
    {
        (*s).inpuMap[i] = i;
    }
    for(int i = 0; i< sizeof((*s).stringPool))
    {
        (*s).stringPool[i] = *StringPool();
    }
    (*s).clsnSpr = *newSprite()
	(*s).clsnSpr.Size, s.clsnSpr.Pal = [...]uint16{1, 1}, make([]uint32, 256);
	(*s).clsnSpr.SetPxl([]byte{0});
	(*s).resetOverrideCharData();
	systemScriptInit(l);

    //Window icon
    if(sizeof((*s).windowMainIconLocation > 0))
    {
        // First we initialize arrays.
		f := make([]io.ReadCloser, len(s.windowMainIconLocation) )
		s.windowMainIcon = make([]image.Image, len(s.windowMainIconLocation))
		// And then we load them.
		for i, iconLocation := range s.windowMainIconLocation {
			f[i], _ = os.Open(iconLocation)
			s.windowMainIcon[i], _, err = image.Decode(f[i])
		}
		s.window.SetIcon(s.windowMainIcon)
		chk(err)
    }

    //TODO:Print error through a concurrent function like the one below
    go func() {
		stdin := bufio.NewScanner(os.Stdin)
		for stdin.Scan() {
			if err := stdin.Err(); err != nil {
				s.errLog.Println(err.Error())
				return
			}
			s.commandLine <- stdin.Text()
		}
	}()
    */

    //return l; try to make this return the lua state
}

int32_t SetWindowSize(System *s, int32_t w, int32_t h)
{
    (*s).sccrect[2] = w, (*s).sccrect[3] = h;

    if((*s).sccrect[2] * 3 > (*s).sccrect[3] * 4)
    {
        (*s).gameWidth, (*s).gameHeight = (*s).sccrect[2] * 3 * 320, 240;
    }
    else
    {
        /* code */
    }
     
}

int LoadChar()//Figure how the fuck you shoud declare this function
{

}

