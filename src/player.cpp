#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "player.h"

using namespace std;

Player::Player(string sName, string sEmail){
    Name = sName;
    Email = sEmail;
    Score = -1;
    Pos[0] = 0;
    Pos[1] = 0;
}
string Player::getName(){
    return Name;
}
double Player::getScore(){
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
void Player::getDataPlayer(){
    string line;
    do{
        cout << "Introduce your name, please: ";
        cin >> Name;
        ifstream File("scores/" + Name + ".txt");
        if(File.is_open()){
            while(getline(File, line)){
                if(line.find("Email:") != string::npos){
                    Email = line.substr(line.find("Email: ") + 7); //sizeof("Email: ") = 7
                }
                if(line.find("Score:") != string::npos){
                    Score = stod(line.substr(line.find("Score: ") + 7)); //sizeof("Score: ") = 7
                }
                if(line.find("Name:") != string::npos){
                    Name = line.substr(line.find("Name: ") + 6); //sizeof("Name: ") = 6
                }
            }
            File.close();
        }else{
            cout << "Player not founded. Try again." << endl;
        }
    }while(Score == -1);
}
void Player::setName(){
    cout << "Introduce your Name, please: ";
    cin >> Name;
    ofstream File;
    File.open("scores/" + Name + ".txt",ios::out | ios::app); //out es para crear, app para añadir
    if(File.is_open()){
        File << "Name: " + Name << endl;
    }
    File.close();
}
void Player::setScore(time_t *t2, time_t *t1){
    if(Score > difftime(*t2, *t1)){  //the smaller, the better the marker
        cout << "You have beat your Score!!" << endl;
        Score = difftime(*t2, *t1);
        ofstream File;
        File.open("scores/" + Name + ".txt",ios::out); //I have not to add, I have to rewrite to correct the Score
        if(File.is_open()){
            File << "Name: " + Name << endl;
            File << "Email: " + Email << endl;
            File << "Score: " + to_string(Score) << endl;
        }
        File.close();
    }else{
        cout << "You didn't beat your score!!" << endl;
        cout << "\nThis time was: " + to_string((int)difftime(*t2, *t1)) << endl;
    }
}
void Player::setEmail(){
    cout << "Introduce your Email, please: ";
    cin >> Email;
    ofstream File;
    File.open("scores/" + Name + ".txt",ios::out | ios::app);
    if(File.is_open()){
        File << "Email: " + Email << endl;
    }
    File.close();
}
void Player::Move(){
    char mov = ' ';
    cout << "\nWhich movement do you like to do?: ";
    cin >> mov;
    switch (mov) //wasd, like in normal games
    {
    case 's': //down
        *(Pos + 1) += 1;   //down is up in the array
        break;
    case 'd': //right
        *Pos += 1;
        break;
    case 'a': //left
        *Pos -= 1;
        break;
    case 'w': //up
        *(Pos + 1) -= 1;  //up is down in the array
        break;
    default:
        break;
    }
}
void Player::CheckGameOver(){
    if((Pos[0] >= 10) || (Pos[0] < 0) || (Pos[1] >= 10) || (Pos[1] < 0)){
        cout << "\n\n===================" <<endl;
        cout << "<<<  GAME OVER  >>>" << endl;
        cout << "===================\n\n" << endl;
        isGameOver = true;
    }else{
        isGameOver = false;
    }
}
Player::~Player(){}