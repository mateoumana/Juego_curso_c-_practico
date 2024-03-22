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

    Player Persona1; //without () to use the default constructor
    Map mapa("mapaLevel1.txt");
    mapa.DrawIntro("IntroFile.txt");
    cout << "\n\nLabyrinth of Practical course of C++" << endl;
    cout << "\nThere are three diferent levels" << endl;
    cout << "Posible movements: d (right), a (left), w (up), s (down)" << endl;
    cout << "||                  [ w ]                  ||" << endl;
    cout << "||            [ a ] [ s ] [ d ]            ||" << endl << endl;
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
    cout << "\n\n===================" <<endl;
    cout << "<<<   LEVEL 1   >>>" << endl;
    cout << "===================\n\n" << endl;
    time(&t1);
    while(Persona1.getGameOver() == false){
        mapa.DrawMap(&Persona1);
        if((mapa.getName() == "mapaLevel2.txt") && mapa.getChange()){
            mapa.otherMap("mapaLevel2.txt");
            cout << "\n\n===================" <<endl;
            cout << "<<<   LEVEL 2   >>>" << endl;
            cout << "===================\n\n" << endl;
            mapa.DrawMap(&Persona1);
        }else if((mapa.getName() == "mapaLevel3.txt") && mapa.getChange()){
            mapa.otherMap("mapaLevel3.txt");
            cout << "\n\n===================" <<endl;
            cout << "<<<   LEVEL 3   >>>" << endl;
            cout << "===================\n\n" << endl;
            mapa.DrawMap(&Persona1);
        }
        Persona1.Move();
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