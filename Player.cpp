#include "Player.h"

// constructor
Player::Player(GameMechs* thisGMRef) {
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // default starting pos is the middle of the board
    objPos init;
    init = objPos(15, 7, '*');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(init);
}

Player::~Player() {
    // delete any heap members here
    delete mainGameMechsRef;
    delete playerPosList;
}

// player pos getter
objPosArrayList* Player::getPlayerPos() {
    // return the reference to the playerPos arrray list
    return playerPosList;
}

// updates player posistion enum
void Player::updatePlayerDir() {
    // PPA3 input processing logic
    if (mainGameMechsRef->getInput() != 0) {
        switch (mainGameMechsRef->getInput()) {
            case 'w':
                if (myDir != DOWN) myDir = UP;
                break;
            case 'a':
                if (myDir != RIGHT) myDir = LEFT;
                break;
            case 's':
                if (myDir != UP) myDir = DOWN;
                break;
            case 'd':
                if (myDir != LEFT) myDir = RIGHT;
                break;
            case 27:
                this->mainGameMechsRef->setExitTrue();
                myDir = STOP; // prevents wrong exit message from displaying
                break;
            default:
                break;
        }
    }
}

// moves player in desired direction
void Player::movePlayer() {
    // PPA3 Finite State Machine logic
    objPos updatedPos;
    objPos foodPos;
    objPos check;
    this->playerPosList->getHeadElement(updatedPos);
    this->mainGameMechsRef->getFoodPos(foodPos);
    switch (myDir) {
        case UP:
            updatedPos.y--;
            if (updatedPos.y < 1) updatedPos.y = mainGameMechsRef->getBoardSizeY() - 2;
            break;
        case LEFT:
            updatedPos.x--;
            if (updatedPos.x < 1) updatedPos.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;
        case DOWN:
            updatedPos.y++;
            if (updatedPos.y > mainGameMechsRef->getBoardSizeY() - 2) updatedPos.y = 1;
            break;
        case RIGHT:
            updatedPos.x++;
            if (updatedPos.x > mainGameMechsRef->getBoardSizeX() - 2) updatedPos.x = 1;
            break;
        default:
            break;
    }
    playerPosList->insertHead(updatedPos);
    if (updatedPos.x == foodPos.x && updatedPos.y == foodPos.y) {
        mainGameMechsRef->generateFood(this->playerPosList);
        mainGameMechsRef->incrementScore();
    }
    else {
        playerPosList->removeTail();
    }
    for (int i = 1; i < this->playerPosList->getSize(); i++) {
        playerPosList->getElement(check, i);
        if (check.x == updatedPos.x && check.y == updatedPos.y) {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }
}