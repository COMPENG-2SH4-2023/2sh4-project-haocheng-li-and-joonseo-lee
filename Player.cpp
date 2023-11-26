#include "Player.h"

Player::Player(GameMechs* thisGMRef) {
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos = objPos(15, 7, '*');
}

Player::~Player() {
    // delete any heap members here
    delete mainGameMechsRef;
}

void Player::getPlayerPos(objPos &returnPos) {
    // return the reference to the playerPos arrray list
    returnPos = playerPos;
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
    switch (myDir) {
        case UP:
            playerPos.y--;
            if (playerPos.y < 1) playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
            break;
        case LEFT:
            playerPos.x--;
            if (playerPos.x < 1) playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;
        case DOWN:
            playerPos.y++;
            if (playerPos.y > mainGameMechsRef->getBoardSizeY() - 2) playerPos.y = 1;
            break;
        case RIGHT:
            playerPos.x++;
            if (playerPos.x > mainGameMechsRef->getBoardSizeX() - 2) playerPos.x = 1;
            break;
        default:
            break;
    }
}