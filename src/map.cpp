#include <iostream>
#include <fstream>
#include <string>
#include "map.h"

using namespace std;

Map::Map(string nameMap){
    int j = 0;
    string line;
    ifstream File(nameMap + ".txt");
    if(File.is_open()){
        while(getline(File, line)){
            for(int i = 0 ;i < sizeof(line); i++){
                cells[j][i].setCell(line[i]);
            }
            j += 1;
        }
    }
}
void DrawMap(){
    int y = 0;
    int i = 0;
    /*for(int i = 0 ;i < SIZE_LAB; i++){
        for(int j = 0 ;j < SIZE_LAB; j++){
            
        }
    }*/
    /*for(int x = 0 ;x < SIZE_LAB;x++){
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
    }*/
}
Map::~Map(){

}