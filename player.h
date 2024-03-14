#ifndef PLAYER.H
#define PLAYER:H

using namespace std;

class Player{
    private:

    protected:
        int Score;
        string Name;
        string Email;
    public:
        Player(string sName, string sEmail, sring sScore);
        ~Player();
        getName();
        getScore();
        getEmail();
};

#endif
