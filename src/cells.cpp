#include <iostream>
#include <fstream>
#include <string>
#include "cells.h"

using namespace std;

Cells::Cells(){
    index = 0;
}
int Cells::getCell(){
    return index;
}
void Cells::setCell(char cell){
    index = cell;
}
Cells::~Cells(){

}