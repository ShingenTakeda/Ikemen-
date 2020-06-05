
#include <string>
#include <map>
#include <mutex>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "sol2/sol.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

//REMEMBER: refer to system.go and system.ssk on the ikemenGO and ikemen directories
//REMEMBER: uncomment the stuff in the System struc after implementing the functions
//TODO: put the "type"s golang declarations up here somewhere

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
    //WinCntMap  winCntMap;
    std::string winCntFileName;
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
    //TODO: find how to do this std::string externalShaders[][m];

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
    //MatchClearance matchClearance[2];
    int32_t consecutiveWins[2];
    std::string commonConst;
    std::string commonScore;
    std::string commonTag;
    float gameSpeed;
    //Preloading preloading;
};

struct OverrideCharData
{
    int32_t power;
    int32_t life;
    int32_t lifeMax;
    float lifeRatio;
    float attackRatio;
};

struct MathClearance
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
    //LoaderState state;
    //channel LoaderState loadExit;
    //TODO:error is a basic type in golang, try to do the same in c++
    //error err;
};