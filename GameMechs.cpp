#include "GameMechs.h"

GameMechs::GameMechs() {
    this->input = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->boardSizeX = 30;
    this->boardSizeY = 15;
    this->score = 0;
}

GameMechs::GameMechs(int boardX, int boardY) {
    this->input = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->boardSizeX = boardX;
    this->boardSizeY = boardY;
    this->score = 0;
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
