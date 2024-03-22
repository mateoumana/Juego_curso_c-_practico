#ifndef MAP_H
#define MAP_H

#include "cells.h"
#include "player.h"
using namespace std;

class Map{
    private:

    protected:
        Cells cell[ROWS][COLUMNS];
        string nameMap;
        bool changeMap = false;
    public:
        Map(string sNameMap);
        ~Map();
        //Get and Set
        string getName();
        bool getChange();
        void otherMap(string sMap);
        void DrawMap(Player *Persona);
        void DrawIntro(string nameIntro);
};

#endif