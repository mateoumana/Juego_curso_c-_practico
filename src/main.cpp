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

void printMap(Player *Persona, char *mapWorld){
    int y = 0;
    int i = 0;
    for(int x = 0 ;x < SIZE_LAB;x++){
        if((y == Persona->getPosY()) && (i == Persona->getPosX())){
            if(((x + 1) % 10) == 0){
                cout << "H" << endl;
            }else{
                cout << "H";
            }
        }else{
            if(((x + 1) % 10) == 0){
                i = -1;
                cout << *(mapWorld + x) << endl;
                y += 1;
            }else{
                cout << *(mapWorld + x);
            }
        }
        i += 1;  
    }    
    //Persona->CheckGameOver();
}

int main(){
    time_t t1, t2;
    int heroPos[2] = {0,0};  //pos x,y
    char option = ' ';
    char mapWorld[SIZE_LAB] = {'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I',
                        'I','I','I','I','I','I','I','I','I','I'};

    Player Persona1("Mateo", "m@gmail.com");

    cout << "Labyrinth Practical course of C++" << endl;
    cout << "Posible movements; d (right), a (left), w (up), s (down)" << endl;
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

    printMap(&Persona1, mapWorld);
    time(&t1);
    while(Persona1.getGameOver() == false){
        Persona1.Move();
        printMap(&Persona1, mapWorld);
        Persona1.CheckGameOver();
    }
    time(&t2);
    Persona1.setScore(&t2, &t1);
    cout << "\nYour best Score is: " << Persona1.getScore() << " seconds" << endl;
    //Persona1.~Persona();
    return 0;
}