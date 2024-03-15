#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
//size of the labyrinth 10*10=100
#define SIZE_LAB 100
using namespace std;
static bool isGameOver = false;

bool CheckGameOver(Player *Persona){
    if((Persona->getPosX() >= 10) || (Persona->getPosX() < 0) || (Persona->getPosY() >= 10) || (Persona->getPosY() < 0)){
        cout << "\n\n===================" <<endl;
        cout << "<<<  GAME OVER  >>>" << endl;
        cout << "===================" << endl << endl;
        return true;
    }else{
        return false;
    }
}

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
    isGameOver = CheckGameOver(Persona);
}

void loginPlayer(){  //third line to the score
    string namePlayer, Email;
    cout << "Introduce your Nick Name: ";
    cin >> namePlayer;
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
    cin >> namePlayer;
    ifstream File(namePlayer + ".txt");
    if(File.is_open()){
        while(getline(File, line)){
            cout << line << endl;
        }
    }
    File.close();
}

int main(){

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

    Player Persona1("Mateo", "m@gmail.com",0);

    cout << "Labyrinth Practical course of C++" << endl;
    cout << "posible movements; r (right), l (left), u (up), d (down)" << endl;
    printMap(&Persona1, mapWorld);
    while(isGameOver == false){
        Persona1.Move();
        printMap(&Persona1, mapWorld);
    }
    cout << "x: " << Persona1.getPosX() << endl;
    cout << "y: " << Persona1.getPosY() << endl;
    //Persona1.~Persona();
    return 0;
}