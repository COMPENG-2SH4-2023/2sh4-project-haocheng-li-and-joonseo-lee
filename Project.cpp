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

    srand(time(NULL));
    gameMechs = new GameMechs();
    player = new Player(gameMechs);
    objPos playerPos;
    player->getPlayerPos(playerPos);
    gameMechs->generateFood(playerPos);
}

void GetInput(void) {
    if (MacUILib_hasChar()) gameMechs->setInput(MacUILib_getChar());
}

void RunLogic(void) {
    player->updatePlayerDir();
    player->movePlayer();

    //  ====================FOR DEBUG ONLY====================
    objPos playerPos;
    player->getPlayerPos(playerPos);
    if (gameMechs->getInput() == 'f') gameMechs->generateFood(playerPos);
    //  ====================FOR DEBUG ONLY====================

    gameMechs->setInput(0);
}

void DrawScreen(void) {
    MacUILib_clearScreen();
    objPos playerPos;
    objPos foodPos;
    player->getPlayerPos(playerPos);
    gameMechs->getFoodPos(foodPos);
    for (int i = 0; i < gameMechs->getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++) {
            if (i == 0 || i == gameMechs->getBoardSizeY() - 1 
            || j == 0 || j == gameMechs->getBoardSizeX() - 1) {
                MacUILib_printf("#");
            }
            else if (i == playerPos.y && j == playerPos.x) {
                MacUILib_printf("%c", playerPos.symbol);
            }
            else if (i == foodPos.y && j == foodPos.x) {
                MacUILib_printf("%c", foodPos.symbol);
            }
            else {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
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
