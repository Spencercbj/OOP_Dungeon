#include"Swamp.h"

using namespace std;

Swamp::Swamp(){}

Swamp::Swamp(bool isExit, int index, vector<Object*> object,int roomHunger,int roomThirst, int roomPoison)
:Room(isExit,index,object,"Swamp",roomHunger,roomThirst,roomPoison){}

void Swamp::setPlayerPoi(Player& player)
{
    player.setPoison(10);
}
