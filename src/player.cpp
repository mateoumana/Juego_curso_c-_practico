#include <iostream>
#include <fstream>
#include <string>
#include "player.h"

using namespace std;

Player::Player(string sName, string sEmail, int sScore){
    Name = sName;
    Email = sEmail;
    Score = sScore;
    Pos[0] = 0;
    Pos[1] = 0;
}
string Player::getName(){
    return Name;
}
int Player::getScore(){
    return Score;
}
int Player::getPosX(){
    return Pos[0];
}
int Player::getPosY(){
    return Pos[1];
}
bool Player::getGameOver(){
    return isGameOver;
}
string Player::getEmail(){
    return Email;
}
string Player::setName(string sName){
    Name = sName;
}
int Player::setScore(int sScore){
    Score = sScore;
}
string Player::setEmail(string sEmail){
    Email = sEmail;
}
void Player::Move(){
    char mov = ' ';
    cout << "Which movement do you like to do?: ";
    cin >> mov;
    switch (mov)
    {
    case 'd': //down
        *(Pos + 1) += 1;   //down is up in the array
        break;
    case 'r': //right
        *Pos += 1;
        break;
    case 'l': //left
        *Pos -= 1;
        break;
    case 'u': //up
        *(Pos + 1) -= 1;  //up is down in the array
        break;
    default:
        break;
    }
}
bool Player::CheckGameOver(){
    if((Pos[0] >= 10) || (Pos[0] < 0) || (Pos[1] >= 10) || (Pos[1] < 0)){
        cout << "\n\nYour Score was:" << Score << endl;
        cout << "\n\n===================" <<endl;
        cout << "<<<  GAME OVER  >>>" << endl;
        cout << "===================" << endl << endl;
        isGameOver true;
    }else{
        isGameOver false;
    }
}
Player::~Player(){}