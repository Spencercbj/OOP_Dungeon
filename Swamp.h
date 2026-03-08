#ifndef SWAMP_H_INCLUDED
#define SWAMP_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"Room.h"
#include"Object.h"
#include"Player.h"

using namespace std;

class Swamp: public Room
{
private:

public:
    Swamp();
    Swamp(bool,int,vector<Object*>,int,int,int);
    void setPlayerPoi(Player&);
};


#endif // SWAMP_H_INCLUDED
