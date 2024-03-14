#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
//size of the labyrinth 10*10=100
#define SIZE_LAB 100
using namespace std;
static bool isGameOver = false;

bool CheckGameOver(int *heroPos){
    if((*(heroPos) >= 10) || (*(heroPos) < 0) || (*(heroPos + 1) >= 10) || (*(heroPos + 1) < 0)){
        cout << "\n\n===================" <<endl;
        cout << "<<<  GAME OVER  >>>" << endl;
        cout << "===================" << endl << endl;
        return true;
    }else{
        return false;
    }
}

void printMap(int *heroPos, int *lifes, char *mapWorld){
    int y = 0;
    int i = 0;
    for(int x = 0 ;x < SIZE_LAB;x++){
        //cout << "/" << (y == *(heroPos + 1)) << (i == *heroPos) << "/ ";
        //cout << "/" << i << *heroPos << "/ " << endl;
        if((y == *(heroPos + 1)) && (i == *heroPos)){
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
    isGameOver = CheckGameOver(heroPos);
}

void movement(char *mov,int *heroPos, int *lifes, char *mapWorld){
    switch (*mov)
    {
    case 'd': //down
        *(heroPos + 1) += 1;   //up is down in the array
        printMap(heroPos, lifes, mapWorld);
        break;
    case 'r': //right
        *heroPos += 1;
        printMap(heroPos, lifes, mapWorld);
        break;
    case 'l': //left
        *heroPos -= 1;
        printMap(heroPos, lifes, mapWorld);
        break;
    case 'u': //up
        *(heroPos + 1) -= 1; //down is up in the array
        printMap(heroPos, lifes, mapWorld);
        break;
    default:
        break;
    }
}

void loginPlayer(){  //third line to the score
    string namePlayer, Email;
    cout << "Introduce your Nick Name: ";
    cin << namePlayer;
    cout << "\nIntroduce your Email: ";
    ofstream File(namePlayer + ".txt");
    if(File.is_open()){
        File << namePlayer << endl;
        File << Email << endl;
    }
    File.close();
}

void selectPlayer(){
    string namePlayer;
    string line;
    cout << "Introduce your Nick Name: ";
    cin << namePlayer;
    ifstream File(namePlayer + ".txt");
    if(File.is_open()){
        while(getline(File, line)){
            cout << line << endl;
        }
    }
    File.close();
}

int main(){
    char mov = ' ';
    int heroPos[2] = {0,0};  //pos x,y
    int lifes = 3;
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

    cout << "Labyrinth Practical course of C++" << endl;
    while((option != 'y') || (option != 'n')){
        cout << "Do you have already an account? (y/n): ";
        cin >> option;
    }
    switch (option){
        case 'y':
            selectPlayer();
            break;
        case 'n':
            loginPlayer();
            break;
    }
    cout << "posible movements; r (right), l (left), u (up), d (down)" << endl;
    printMap(heroPos, &lifes, mapWorld);
    while(isGameOver == false){
        cout << "\n>>>Which movement do you wish to do?: " << endl;
        cin >> mov;
        movement(&mov,heroPos, &lifes, mapWorld);
    }
    return 0;
}