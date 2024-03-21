#ifndef MAP_H
#define MAP_H

#include "cells.h"
#include "player.h"
using namespace std;

class Map{
    private:

    protected:
        Cells cell[ROWS][COLUMNS];
    public:
        Map(string nameMap);
        ~Map();
        //Get and Set
        void DrawMap(Player *Persona);
        void DrawIntro(string nameIntro);
};

#endif