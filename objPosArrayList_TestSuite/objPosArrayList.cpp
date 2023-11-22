#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() {
    this->sizeArray = 200;
    this->aList = new objPos[this->sizeArray];
    this->sizeList = 0;
    for (int i = 0; i < this->sizeArray; i++) {
        this->aList[i] = objPos();
    }
}

objPosArrayList::~objPosArrayList() {
    delete [] this->aList;
}

int objPosArrayList::getSize() {
    return this->sizeList;
}

void objPosArrayList::insertHead(objPos thisPos) {
    for (int i = this->sizeList; i > 0; i--) {
        this->aList[i] = this->aList[i - 1];
    }
    this->aList[0] = thisPos;
    this->sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos) {
    this->aList[this->sizeList] = thisPos;
    this->sizeList++;
}

void objPosArrayList::removeHead() {
    for (int i = 0; i < this->sizeList - 1; i++) {
        this->aList[i] = this->aList[i + 1];
    }
    this->removeTail();
}

void objPosArrayList::removeTail() {
    this->aList[this->sizeList - 1] = objPos();
    this->sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos) {
    returnPos.x = this->aList[0].x;
    returnPos.y = this->aList[0].y;
    returnPos.symbol = this->aList[0].symbol;
}

void objPosArrayList::getTailElement(objPos &returnPos) {
    returnPos.x = this->aList[this->sizeList - 1].x;
    returnPos.y = this->aList[this->sizeList - 1].y;
    returnPos.symbol = this->aList[this->sizeList - 1].symbol;
}

void objPosArrayList::getElement(objPos &returnPos, int index) {
    returnPos.x = this->aList[index].x;
    returnPos.y = this->aList[index].y;
    returnPos.symbol = this->aList[index].symbol;
}