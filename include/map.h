#ifndef MAP_H
#define MAP_H

#include "cells.h"
using namespace std;

class Map{
    private:

    protected:
        Cells cells[12][15];
    public:
        Map(string nameMap);
        ~Map();
        //Get and Set
        void DrawMap();
};

#endif