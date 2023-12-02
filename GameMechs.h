#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "MacUILib.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int boardSizeX;
        int boardSizeY;
        int score;
        objPosArrayList* foodBucket;

        void generateFood(objPosArrayList* playerPosList, objPosArrayList* foodPosList, bool isSpecial,  objPos &foodPos);
        void clearFood();
        void randomize(int &num, int lower, int upper);

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();
        
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        void setExitTrue();
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();
        void incrementScore();
        void increaseScore(int score);

        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();

        void generateFoodList(objPosArrayList* playerPosList);
        objPosArrayList* getFoodBucket();
};

#endif