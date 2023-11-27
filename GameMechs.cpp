#include "GameMechs.h"

GameMechs::GameMechs() {
    this->input = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->boardSizeX = 30;
    this->boardSizeY = 15;
    this->score = 0;
    this->foodPos = objPos(0, 0, 'F');
}

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

bool GameMechs::getExitFlagStatus() {
    return this->exitFlag;
}

bool GameMechs::getLoseFlagStatus() {
    return this->loseFlag;
}

char GameMechs::getInput() {
    return this->input;
}

int GameMechs::getBoardSizeX() {
    return this->boardSizeX;
}

int GameMechs::getBoardSizeY() {
    return this->boardSizeY;
}

int GameMechs::getScore() {
    return this->score;
}

void GameMechs::setExitTrue() {
    this->exitFlag = true;
}

void GameMechs::setLoseFlag() {
    this->loseFlag = true;
}

void GameMechs::setInput(char this_input) {
    this->input = this_input;
}

void GameMechs::clearInput() {
    this->input = 0;
}

void GameMechs::incrementScore() {
    this->score++;
}

void GameMechs::generateFood(objPos blockOff) {
    int row, col;
    bool isBlocked = true;
    while (isBlocked) {
        randomize(row, 1, boardSizeY - 1);
        randomize(col, 1, boardSizeX - 1);
        isBlocked = row == blockOff.y && col == blockOff.x;
    }
    foodPos.y = row;
    foodPos.x = col;
}

void GameMechs::getFoodPos(objPos &returnPos) {
    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
    returnPos.symbol = foodPos.symbol;
}

void GameMechs::randomize(int &num, int lower, int upper) {
    num = (rand() % (upper - lower)) + lower;
}