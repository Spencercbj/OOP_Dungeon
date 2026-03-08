#include"Desert.h"
#include"Room.h"

using namespace std;

Desert::Desert(){}

Desert::Desert(bool isExit, int index, vector<Object*> object, int roomHunger, int roomThirst, int roomPoison,int isOasis, int isSandstorm)
:Room(isExit,index,object,"Desert",roomHunger,roomThirst,roomPoison)
{
    this->isOasis=isOasis;

    this->isSandstorm=isSandstorm;
}

void Desert::setPlayerThir(Player& player)
{
    player.setThirst(10);
}

void Desert::sandstorm(Player& player)
{
    player.setThirst(10);
    player.setHunger(10);
}

void Desert::Oasis(Player& player)
{
    player.setThirst(0);
}

int Desert::getIsOasis()
{
    return isOasis;
}

int Desert::getIsSandstorm()
{
    return isSandstorm;
}
