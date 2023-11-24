#include <iostream>
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* mechs;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void) {
    Initialize();
    while(mechs->getExitFlagStatus() == false) {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void) {
    MacUILib_init();
    MacUILib_clearScreen();
    mechs = new GameMechs();
}

void GetInput(void) {
    if (MacUILib_hasChar()) {
        mechs->setInput(MacUILib_getChar());
    }
}

void RunLogic(void) {
    
}

void DrawScreen(void) {
    MacUILib_clearScreen();    

}

void LoopDelay(void) {
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void) {
    MacUILib_clearScreen();    
    delete mechs;

    MacUILib_uninit();
}
