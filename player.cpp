#include <iostream>
#include <fstream>
#include <string>
#include "player.h"

using namespace std;

Player::Player(string sName, string sEmail, sring sScore){
    Name = sName;
    Email = sEmail;
    Score = sScore;
}
Player::getName(){
    return Name;
}
Player::getScore(){
    return Score;
}
Player::getEmail(){
    return Email;
}
Player::~Player(){}