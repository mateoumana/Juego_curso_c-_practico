#ifndef PLAYER.H
#define PLAYER.H

using namespace std;

class Player{
    private:

    protected:
        int Score;
        string Name;
        string Email;
        int Pos[2] = {0,0}; //default

    public:
        Player(string sName, string sEmail, int sScore);
        ~Player();
        //Get and Set
        string getName();
        int getScore();
        int getPosX();
        int getPosY();
        string getEmail();
        string setName(string sName);
        int setScore(int sScore);
        string setEmail(string sEmail);
        //Movement
        void Move();
};

#endif