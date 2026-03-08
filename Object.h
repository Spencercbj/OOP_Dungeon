#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item;
class Magic;

class Object
{
private:
    string name;
    string tag;
public:
    Object();
    Object(string,string);

    /* pure virtual function */
    virtual bool triggerEvent(Object*,int,int,int) = 0;
    virtual void addItem(Item);
    virtual void increaseStates(int,int,int,int,int,int,int,int);
    virtual void addMagic(Magic);
    virtual vector<Magic> getMagic();
    virtual bool checkIsDead();
    virtual void takeDamage(int);
    virtual void setMaxHealth(int);
    virtual void setCurrentHealth(int);
    virtual void setAttack(int);
    virtual void setDefense(int);
    virtual int getMaxHealth();
    virtual int getCurrentHealth();
    virtual int getAttack();
    virtual int getDefense();
    virtual void setMp(int);
    virtual int getMp();
    virtual void setHunger(int);
    virtual void setThirst(int);
    virtual int getDebuff();
    virtual int getHunger();
    virtual int getThirst();
    virtual int getPoison();
    virtual int getMoney();
    virtual void setPoison(int);
    virtual int getHealth();
    virtual int getPrice();
    virtual int getDamage();
    virtual int getMpUsed();
    virtual void setMoney(int);
    /* Set & Get function*/
    void setName(string);
    void setTag(string);
    string getName();
    string getTag();
};

#endif // OBJECT_H_INCLUDED
