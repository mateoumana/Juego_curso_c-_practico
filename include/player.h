#ifndef PLAYER_H
#define PLAYER_H


#define ROWS 12
#define COLUMNS 15
using namespace std;//without this, string doesn't work

class Player{
    private:

    protected:
        double Score;
        string Name = " ";
        string Email = " ";
        int Pos[2] = {1,1}; //default
        bool isGameOver = false;

    public:
        Player(string sName, string sEmail);
        Player();
        ~Player();
        //Get and Set
        string getName();
        double getScore();
        int getPosX();
        int getPosY();
        bool getGameOver();
        string getEmail();
        void getDataPlayer(); //get dat from player who are already registered
        void setName();
        void setScore(time_t *t2, time_t *t1);
        void setEmail();
        //Movement
        void Move();
        void CheckGameOver(char cell);
};

#endif
