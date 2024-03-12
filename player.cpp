#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Player{
    private:
        string Name;
        string Email;
        string Score;
    public:
        Player(string sName, string sEmail, sring sScore){
            Name = sName;
            Email = sEmail;
            Score = sScore;
        }
        getName(){
            return Name;
        }
        getScore(){
            return Score;
        }
        getEmail(){
            return Email;
        }
};