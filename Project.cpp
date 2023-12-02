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

    // init pseudo-random num gen
    srand(time(NULL));
    // init pointers on heap
    gameMechs = new GameMechs();
    player = new Player(gameMechs);
    // generate first location of food
    objPosArrayList* playerPos = player->getPlayerPos();
    gameMechs->generateFoodList(playerPos);
}

void GetInput(void) {
    // sets keyboard input to the input in the GameMechs class for further processing
    if (MacUILib_hasChar()) gameMechs->setInput(MacUILib_getChar());
}

void RunLogic(void) {
    player->updatePlayerDir();
    player->movePlayer();

    gameMechs->clearInput();
}

void DrawScreen(void) {
    MacUILib_clearScreen();
    objPosArrayList* playerPos = player->getPlayerPos();
    objPosArrayList* foodBucket = gameMechs->getFoodBucket();
    objPos playerCheck;
    bool check;
    for (int i = 0; i < gameMechs->getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++) {
            check = false;
            // prints border
            if (i == 0 || i == gameMechs->getBoardSizeY() - 1 
            || j == 0 || j == gameMechs->getBoardSizeX() - 1) {
                MacUILib_printf("#");
            }
            else {
                // prints food
                if (foodBucket->contains(j, i)) {
                    MacUILib_printf("%c", foodBucket->getSymbol(j, i));
                    check = true;
                }
                // prints snake body
                for (int k = 0; !check && k < playerPos->getSize(); k++) {
                    playerPos->getElement(playerCheck, k);
                    if (i == playerCheck.y && j == playerCheck.x) {
                        MacUILib_printf("%c", playerCheck.symbol);
                        check = true;
                    }
                }
                // prints empty space
                if (!check) {
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d", gameMechs->getScore());
}

void LoopDelay(void) {
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void) {
    MacUILib_clearScreen();
    // print lose message
    if (gameMechs->getLoseFlagStatus()) {
        MacUILib_printf("You Lose! \nScore: %d", gameMechs->getScore());
    }
    // print exit by key message
    else {
        MacUILib_printf("Game Terminated. \nScore: %d", gameMechs->getScore());
    }
    // delete heap members
    delete gameMechs;
    delete player;

    MacUILib_uninit();
}
