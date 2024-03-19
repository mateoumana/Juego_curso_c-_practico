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
    int y = 0;
    int i = 0;
    for(int i = 0 ;i < ROWS; i++){
        for(int j = 0 ;j < COLUMNS; j++){
            if((i == Persona->getPosY()) && (j == Persona->getPosX())){
                cout << "H";
                Persona->CheckGameOver(cell[i][j].getCell());
            }else{
                cout << cell[i][j].getCell();
            }
        }
        cout << endl;
    }
}
Map::~Map(){

}