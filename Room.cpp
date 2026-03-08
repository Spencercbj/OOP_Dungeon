#include "Room.h"

using namespace std;

Room::Room(){}

Room::Room(bool isExit, int index, vector<Object*> object, string roomState, int roomHunger, int roomThirst, int roomPoison)
{
    this->isExit=isExit;
    this->index=index;
    for(int i=0;i<object.size();i++)
    {
        objects.push_back(object[i]);
    }
    this->upRoom=NULL;
    this->downRoom=NULL;
    this->leftRoom=NULL;
    this->rightRoom=NULL;
    this->roomState=roomState;
    this->roomHunger=roomHunger;
    this->roomThirst=roomThirst;
    this->roomPoison=roomPoison;
}

bool Room::popObject(Object* usedObject)
{
    int ind;
    for(int i=0;i<objects.size();i++)
    {
        if(objects[i]->getName()==usedObject->getName())
        {
            ind=i;
            break;
        }
    }
    //cout<<"pop Index: "<<ind<<endl;
    objects.erase(objects.begin()+ind);
    return true;
}
void Room::setUpRoom(Room* room)
{
    this->upRoom=room;
}

void Room::setDownRoom(Room* room)
{
    this->downRoom=room;
}

void Room::setLeftRoom(Room* room)
{
    this->leftRoom=room;
}

void Room::setRightRoom(Room* room)
{
    this->rightRoom=room;
}

void Room::setIndex(int index)
{
    this->index=index;
}

void Room::setIsExit(bool isExit)
{
    this->isExit=isExit;
}

void Room::setObjects(vector<Object*> object)
{
    for(int i=0;i<objects.size();i++)
    {
        objects[i]=object[i];
    }
}

void Room::setRoomState(string roomState)
{
    this->roomState=roomState;
}

bool Room::getIsExit()
{
    return isExit;
}

int Room::getIndex()
{
    return index;
}

Room* Room::getUpRoom()
{
    return upRoom;
}

Room* Room::getDownRoom()
{
    return downRoom;
}

Room* Room::getLeftRoom()
{
    return leftRoom;
}

Room* Room::getRightRoom()
{
    return rightRoom;
}

string Room::getRoomState()
{
    return roomState;
}

vector<Object*> Room::getObjects()
{
    return objects;
}

int Room::getRoomHun()
{
    return roomHunger;
}

int Room::getRoomThir()
{
    return roomThirst;
}

int Room::getRoomPoi()
{
    return roomPoison;
}

int Room::getIsOasis(){}

int Room::getIsSandstorm(){}
