#include <iostream>
#include <fstream>
#include <string>
#include "map.h"

using namespace std;

Map::Map(string sNameMap){
    int j = 0;
    nameMap = sNameMap;
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
    File.close();
}
string Map::getName(){
    return nameMap;
}
bool Map::getChange(){
    return changeMap;
}
void Map::otherMap(string sMap){
    int j = 0;
    string line;
    ifstream File("mapas/" + sMap);
    if(File.is_open()){
        while(getline(File, line)){
            for(int i = 0 ;i < COLUMNS; i++){
                cell[j][i].setCell(line[i]);
            }
            j += 1;
        }
    }
    File.close();
}
void Map::DrawMap(Player *Persona){
    Persona->CheckGameOver(cell[Persona->getPosY()][Persona->getPosX()].getCell(), &nameMap, &changeMap);
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
        File.close();
    }else{
        cout << "\nFATAL ERROR: Intro File not founded." << endl;
        cout << "Check the location file: mapas/IntroFile.txt" << endl;
    }
}
Map::~Map(){

}