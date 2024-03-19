#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "player.h"
#include "cells.h"
#include "map.h"
//size of the labyrinth 10*10=100
#define SIZE_LAB 100
using namespace std;

int main(){
    time_t t1, t2;
    int heroPos[2] = {0,0};  //pos x,y
    char option = ' ';

    Player Persona1();
    Map mapa("mapaLevel1.txt");

    cout << "Labyrinth of Practical course of C++" << endl;
    cout << "Posible movements: d (right), a (left), w (up), s (down)" << endl;
    cout << "                  [ w ]       " << endl;
    cout << "            [ a ] [ s ] [ d ] " << endl << endl;
    cout << "Do you have already an account?(y/n): ";
    cin >> option;
    
    while((option != 'y') && (option != 'n')){
        cout << "\nInvalid option, try again." << endl;
        cout << "Do you have already an account?(y/n): ";
        cin >> option;
    }
    switch (option){
    case 'y':
        Persona1.getDataPlayer();
        break;
    case 'n':
        Persona1.setName();
        Persona1.setEmail();
        break;
    }

    mapa.DrawMap(&Persona1);
    time(&t1);
    while(Persona1.getGameOver() == false){
        Persona1.Move();
        mapa.DrawMap(&Persona1);
    }
    time(&t2);
    cout << "\n\n===================" <<endl;
    cout << "<<<  GAME OVER  >>>" << endl;
    cout << "===================\n\n" << endl;
    Persona1.setScore(&t2, &t1);
    cout << "\nYour best Score is: " << Persona1.getScore() << " seconds" << endl;
    //Persona1.~Persona();
    return 0;
}