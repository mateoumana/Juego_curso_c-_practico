#include <iostream>
#include <fstream>
#include <string>
#include "map.h"

using namespace std;

Map::Map(string nameMap){
    int j = 0;
    string line;
    ifstream File("mapas/" + nameMap);
    if(File.is_open()){
        while(getline(File, line)){
            for(int i = 0 ;i < COLUMNS; i++){
                cell[j][i].setCell(line[i]);
            }
            j += 1;
        }
    }
}
void Map::DrawMap(Player *Persona){
    //cout << Persona->getPosX() << Persona->getPosY() << endl;
    Persona->CheckGameOver(cell[Persona->getPosY()][Persona->getPosX()].getCell());
    //cout << Persona->getPosX() << Persona->getPosY() << endl;
    for(int i = 0 ;i < ROWS; i++){
        for(int j = 0 ;j < COLUMNS; j++){
            if((i == Persona->getPosY()) && (j == Persona->getPosX())){
                cout << "H";
            }else{
                cout << cell[i][j].getCell();
            }
        }
        cout << endl;
    }
}
void Map::DrawIntro(string nameIntro){
    string line;
    ifstream File("mapas/" + nameIntro);
    if(File.is_open()){
        while(getline(File, line)){
            cout << line << endl;
        }
    }else{
        cout << "\nFATAL ERROR: Intro File not founded." << endl;
        cout << "Check the location file: mapas/IntroFile.txt" << endl;
    }
}
Map::~Map(){

}