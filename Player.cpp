#include "Player.h"

Player::Player(GameMechs* thisGMRef) {
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos = new objPos(15, 7, '*');
}

Player::~Player() {
    // delete any heap members here
    delete mainGameMechsRef;
}

*objPosArrayList Player::getPlayerPos() {
    // return the reference to the playerPos arrray list
    return playerPosList;
}

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
            default:
                break;
        }
    }
}

void Player::movePlayer() {
    // PPA3 Finite State Machine logic
    objPos updatedPos = objPos(player.x, player.y, '*');
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
    playerPosList->removeHead();
}