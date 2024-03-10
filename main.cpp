#include <iostream>
//size of the labyrinth 10*10=100
#define SIZE_LAB 100
using namespace std;

void printMap(int *heroPos, int *lifes, char *mapWorld){
    for(int i = 0 ;i < SIZE_LAB;i++){
        if(((i + 1) % 10) == 0){
            cout << *(mapWorld + i) << endl;
        }else{
            cout << *(mapWorld + i);
        }
    }
}

void movement(char *mov){
    switch (*mov)
    {
    case 'd':
        /* code */
        break;
    case 'r':
        /* code */
        break;
    case 'l':
        /* code */
        break;
    case 'u':
        /* code */
        break;
    default:
        break;
    }
}

int main(){
    char mov = ' ';
    bool isGameOver = false;
    int heroPos = 1;
    int lifes = 3;
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
    cout << "posible movements; r (right), l (left), u (up), d (down)" << endl;
    while(isGameOver == false){
        cout << "Movimiento: " << endl;
        cin >> mov;
        printMap(&heroPos, &lifes, mapWorld);
        //movement(&mov);
    }
    return 0;
}