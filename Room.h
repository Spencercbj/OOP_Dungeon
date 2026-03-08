#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
    string roomState;
    int roomHunger, roomThirst,roomPoison;
public:
    Room();
    Room(bool, int, vector<Object*>,string,int,int,int);
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/
    //pop完會改成NULL所以要判斷該位置是否為NULL
    /* Set & Get function*/
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    void setRoomState(string);
    bool getIsExit();
    int getIndex();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
    string getRoomState();
    int getRoomHun();
    int getRoomThir();
    int getRoomPoi();
    virtual int getIsOasis();
    virtual int getIsSandstorm();
};

#endif // ROOM_H_INCLUDED
