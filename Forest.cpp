#include"Forest.h"

using namespace std;

Forest::Forest(){}

Forest::Forest(bool isExit, int index, vector<Object*> object,int roomHunger, int roomThirst, int roomPoison)
:Room(isExit,index,object,"Forest",roomHunger,roomThirst,roomPoison){}

void Forest::setPlayerHun(Player& player)
{
    player.setHunger(10);
}
