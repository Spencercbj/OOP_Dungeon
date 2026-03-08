#ifndef FOREST_H_INCLUDED
#define FOREST_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"Room.h"
#include"Object.h"
#include"Player.h"

using namespace std;

class Forest: public Room
{
private:

public:
    Forest();
    Forest(bool,int,vector<Object*>,int,int,int);
    void setPlayerHun(Player&);
};


#endif // FOREST_H_INCLUDED
