#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

// init aList on the heap and set all items in arraylist as empty objPos object
objPosArrayList::objPosArrayList() {
    this->sizeArray = 200;
    this->aList = new objPos[this->sizeArray];
    this->sizeList = 0;
    for (int i = 0; i < this->sizeArray; i++) {
        this->aList[i] = objPos();
    }
}

// frees aList from heap (the only element alloc'd on heap)
objPosArrayList::~objPosArrayList() {
    delete [] this->aList;
}

// returns number of valid elements in array list
int objPosArrayList::getSize() {
    return this->sizeList;
}

// shifts all current elements to the right then updates first element of array
void objPosArrayList::insertHead(objPos thisPos) {
    for (int i = this->sizeList; i > 0; i--) {
        this->aList[i] = this->aList[i - 1];
    }
    this->aList[0] = thisPos;
    this->sizeList++;
}

// adds tail
void objPosArrayList::insertTail(objPos thisPos) {
    this->aList[this->sizeList] = thisPos;
    this->sizeList++;
}

// shifts every item in array list to the left, then removes tail (since it would be duplicate)
void objPosArrayList::removeHead() {
    for (int i = 0; i < this->sizeList - 1; i++) {
        this->aList[i] = this->aList[i + 1];
    }
    this->removeTail();
}

// removes tail
void objPosArrayList::removeTail() {
    // check prevents sizeList becoming < 0 & prevents out of bounds errors
    if (this->sizeList > 0) {
        this->aList[this->sizeList - 1] = objPos();
        this->sizeList--;
    }
}

// returns element in head of array list
void objPosArrayList::getHeadElement(objPos &returnPos) {
    returnPos.x = this->aList[0].x;
    returnPos.y = this->aList[0].y;
    returnPos.symbol = this->aList[0].symbol;
}

// returns element in tail of array list
void objPosArrayList::getTailElement(objPos &returnPos) {
    // prevent out of bounds issues, return null element (all zeros) if nothing in array
    if (this->sizeList > 0) {
        returnPos.x = this->aList[this->sizeList - 1].x;
        returnPos.y = this->aList[this->sizeList - 1].y;
        returnPos.symbol = this->aList[this->sizeList - 1].symbol;
    }
    else {
        returnPos.x = 0;
        returnPos.y = 0;
        returnPos.symbol = 0;
    }
}

// returns element in given position of array
void objPosArrayList::getElement(objPos &returnPos, int index) {
    if (index < 0 || index >= this->sizeList) {
        returnPos.x = 0;
        returnPos.y = 0;
        returnPos.symbol = 0;
    }
    else {
        returnPos.x = this->aList[index].x;
        returnPos.y = this->aList[index].y;
        returnPos.symbol = this->aList[index].symbol;
    }   
}

// returns true if the input position overlaps with any position in the array list, false otherwise
bool objPosArrayList::contains(objPos pos) {
    return contains(pos.x, pos.y);
}

bool objPosArrayList::contains(int x, int y) {
    for (int i = 0; i < sizeList; i++) {
        if (x == aList[i].x && y == aList[i].y) return true;
    }
    return false;
}

// returns the symbol of the first occurence of an objPos with matching coordinates
char objPosArrayList::getSymbol(int x, int y) {
    for (int i = 0; i < sizeList; i++) {
        if (x == aList[i].x && y == aList[i].y) return aList[i].symbol;
    }
    return 0;
}