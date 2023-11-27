#include <iostream>
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *gameMechs;
Player *player;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void) {
    Initialize();

    while(!gameMechs->getExitFlagStatus()) {
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

    gameMechs = new GameMechs();
    player = new Player(gameMechs);
}

void GetInput(void) {
    if (MacUILib_hasChar()) gameMechs->setInput(MacUILib_getChar());
}

void RunLogic(void) {
    player->updatePlayerDir();
    player->movePlayer();
}

void DrawScreen(void) {
    MacUILib_clearScreen();
    objPos playerPos;
    player->getPlayerPos(playerPos);
    for (int i = 0; i < gameMechs->getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++) {
            if (i == 0 || i == gameMechs->getBoardSizeY() - 1 
            || j == 0 || j == gameMechs->getBoardSizeX() - 1) {
                MacUILib_printf("#");
            }
            else {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("%d\n", playerPos.x);
    MacUILib_printf("%d\n", playerPos.y);
}

void LoopDelay(void) {
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void) {
    MacUILib_clearScreen();    
    delete gameMechs;
    delete player;

    MacUILib_uninit();
}
