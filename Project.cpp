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
    objPosArrayList* playerPos = player->getPlayerPos();
    gameMechs->generateFood(playerPos);
}

void GetInput(void) {
    if (MacUILib_hasChar()) gameMechs->setInput(MacUILib_getChar());
}

void RunLogic(void) {
    player->updatePlayerDir();
    player->movePlayer();

    //  ====================FOR DEBUG ONLY====================
    // objPos playerPos;
    // player->getPlayerPos(playerPos);
    // if (gameMechs->getInput() == 'f') gameMechs->generateFood(playerPos);
    //  ====================FOR DEBUG ONLY====================

    gameMechs->setInput(0);
}

void DrawScreen(void) {
    MacUILib_clearScreen();
    objPosArrayList* playerPos;
    objPos playerCheck;
    objPos foodPos;
    playerPos = player->getPlayerPos();
    gameMechs->getFoodPos(foodPos);
    bool check;
    for (int i = 0; i < gameMechs->getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++) {
            check = false;
            if (i == 0 || i == gameMechs->getBoardSizeY() - 1 
            || j == 0 || j == gameMechs->getBoardSizeX() - 1) {
                MacUILib_printf("#");
            }
            else {
                if (i == foodPos.y && j == foodPos.x) {
                    MacUILib_printf("%c", foodPos.symbol);
                    check = true;
                }
                for (int k = 0; !check && k < playerPos->getSize(); k++) {
                    playerPos->getElement(playerCheck, k);
                    if (i == playerCheck.y && j == playerCheck.x) {
                        MacUILib_printf("%c", playerCheck.symbol);
                        check = true;
                    }
                }
                if (!check) {
                    MacUILib_printf(" ");
                }
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
    if (gameMechs->getLoseFlagStatus()) {
        MacUILib_printf("You Lose! \nScore: %d", gameMechs->getScore());
    }
    else {
        MacUILib_printf("Game Terminated. \nScore: %d", gameMechs->getScore());
    }
    delete gameMechs;
    delete player;

    MacUILib_uninit();
}
