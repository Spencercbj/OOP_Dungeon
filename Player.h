#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Magic.h"

using namespace std;

class Item;
class Magic;
class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
    vector<Magic> magics;
    int mp;
    int hunger;
    int thirst;
    int poison;
    int money;
public:
    Player();
    Player(string,int,int,int,int,int);
    void addItem(Item);
    void increaseStates(int,int,int,int,int,int,int,int);
    void changeRoom(Room*);
    void addMagic(Magic);
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*,int,int,int);

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    void setMp(int);
    void setHunger(int);
    void setThirst(int);
    void setPoison(int);
    void setMoney(int);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    int getMp();
    int getHunger();
    int getThirst();
    int getPoison();
    int getMoney();
    vector<Item> getInventory();
    vector<Magic> getMagic();
};

#endif // PLAYER_H_INCLUDED
