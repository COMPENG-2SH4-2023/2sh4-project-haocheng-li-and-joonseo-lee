#include "GameMechs.h"

// default constructor
GameMechs::GameMechs() {
    this->input = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->boardSizeX = 30;
    this->boardSizeY = 15;
    this->score = 0;
    this->foodBucket = new objPosArrayList();
}

// additional constructor with board size designation
GameMechs::GameMechs(int boardX, int boardY) {
    this->input = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->boardSizeX = boardX;
    this->boardSizeY = boardY;
    this->score = 0;
    this->foodBucket = new objPosArrayList();
}

// do you need a destructor?
GameMechs::~GameMechs() {
    delete foodBucket;
}

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

// increase the score by a specified amount
void GameMechs::increaseScore(int score) {
    this->score += score;
}

// generates a single food at random position
void GameMechs::generateFood(objPosArrayList* playerPosList, objPosArrayList* foodPosList, bool isSpecial,  objPos &foodPos) {
    bool isBlocked = true;
    while (isBlocked) {
        // generate random numbers for the x-y coordinates
        randomize(foodPos.y, 1, boardSizeY - 1);
        randomize(foodPos.x, 1, boardSizeX - 1);

        if (isSpecial) foodPos.symbol = 'P';
        else foodPos.symbol = 'F';

        // if any part of the snake's body or any already generated food item overlaps with new food position, regenerate
        isBlocked = playerPosList->contains(foodPos) || foodPosList->contains(foodPos);
    }
}

// generates 5 food items
void GameMechs::generateFoodList(objPosArrayList* playerPosList) {
    clearFood();
    objPos tempFoodPos;
    for (int i = 0; i < 5; i++) {
        generateFood(playerPosList, foodBucket, i < 1, tempFoodPos);
        foodBucket->insertTail(tempFoodPos);
    }
}

// foodBucket getter
objPosArrayList* GameMechs::getFoodBucket() {
    return foodBucket;
}

// helper function to clear foodBucket
void GameMechs::clearFood() {
    int size = foodBucket->getSize();
    for (int i = 0; i < size; i++) {
        foodBucket->removeTail();
    }
}

// helper function to randomize numbers
void GameMechs::randomize(int &num, int lower, int upper) {
    num = (rand() % (upper - lower)) + lower;
}