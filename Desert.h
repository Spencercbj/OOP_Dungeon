#ifndef DESERT_H_INCLUDED
#define DESERT_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"Room.h"
#include"Object.h"
#include"Player.h"

using namespace std;

class Desert: public Room
{
private:
    int isOasis;
    int isSandstorm;
public:
    Desert();
    Desert(bool,int,vector<Object*>,int,int,int,int,int);
    void setPlayerThir(Player&);
    void sandstorm(Player&);
    void Oasis(Player&);
    int getIsOasis();
    int getIsSandstorm();
};


#endif // DESERT_H_INCLUDED
