#include "GameMechs.h"

// default constructor
GameMechs::GameMechs() {
    this->input = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->boardSizeX = 30;
    this->boardSizeY = 15;
    this->score = 0;
    this->foodPos = objPos(0, 0, 'F');
}

// additional constructor with board size designation
GameMechs::GameMechs(int boardX, int boardY) {
    this->input = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->boardSizeX = boardX;
    this->boardSizeY = boardY;
    this->score = 0;
    this->foodPos = objPos(0, 0, 'F');
}

// do you need a destructor?

// exit flag getter
bool GameMechs::getExitFlagStatus() {
    return this->exitFlag;
}

// lose flag getter
bool GameMechs::getLoseFlagStatus() {
    return this->loseFlag;
}

// input getter
char GameMechs::getInput() {
    return this->input;
}

// board x size getter
int GameMechs::getBoardSizeX() {
    return this->boardSizeX;
}

// board y size getter
int GameMechs::getBoardSizeY() {
    return this->boardSizeY;
}

// score getter
int GameMechs::getScore() {
    return this->score;
}

// exit flag setter
void GameMechs::setExitTrue() {
    this->exitFlag = true;
}

// lose flag setter
void GameMechs::setLoseFlag() {
    this->loseFlag = true;
}

// input setter
void GameMechs::setInput(char this_input) {
    this->input = this_input;
}

// clears input
void GameMechs::clearInput() {
    this->input = 0;
}

// increases setter (adds 1 to current score)
void GameMechs::incrementScore() {
    this->score++;
}

// generates food at random position
void GameMechs::generateFood(objPosArrayList* blockOff) {
    int row, col;
    bool isBlocked = true;
    objPos counter;
    while (isBlocked) {
        randomize(row, 1, boardSizeY - 1);
        randomize(col, 1, boardSizeX - 1);
        // if any part of the snake's body overlaps with new food position, regenerate
        for (int i = 0; i < blockOff->getSize(); i++) {
            blockOff->getElement(counter, i);
            isBlocked = row == counter.y && col == counter.x;
            if (isBlocked) {
                break;
            }
        }
    }
    foodPos.y = row;
    foodPos.x = col;
}

// food pos getter
void GameMechs::getFoodPos(objPos &returnPos) {
    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
    returnPos.symbol = foodPos.symbol;
}

// helper function to randomize numbers
void GameMechs::randomize(int &num, int lower, int upper) {
    num = (rand() % (upper - lower)) + lower;
}