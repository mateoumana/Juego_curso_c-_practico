#include <iostream>
using namespace std;

void printMap(int *heroPos, int *lifes, char *mapWorld){
    for(int i ;i < sizeof(mapWorld);i++){
        cout << *(mapWorld + i) << endl;
    }
}

int main(){
    int heroPos = 1;
    int lifes = 3;
    char mapWorld[10] = {'I','I','I','I','I','I','I','I','I','I'};
    cout << "Hola Mateo" << endl;
    printMap(&heroPos, &lifes, mapWorld);
    return 0;
}