#include "Object.h"
#include "Item.h"
#include "Magic.h"
using namespace std;

Object::Object(){}

Object::Object(string name, string tag)
{
    this->name=name;
    this->tag=tag;
}

void Object::setName(string name)
{
    this->name=name;
}

void Object::setTag(string tag)
{
    this->tag=tag;
}

string Object::getName()
{
    return name;
}

string Object::getTag()
{
    return tag;
}

void Object::addItem(Item item){}

void Object::increaseStates(int attack,int defense,int health,int mp,int money,int hunger,int thirst,int poison){}

void Object::addMagic(Magic magic){}

vector<Magic> Object::getMagic(){}

bool Object::checkIsDead(){}

void Object::takeDamage(int damage){}

void Object::setMaxHealth(int health){}

void Object::setCurrentHealth(int health){}

void Object::setAttack(int attack){}

void Object::setDefense(int defense){}

int Object::getMaxHealth(){}

int Object::getCurrentHealth(){}

int Object::getAttack(){}

int Object::getDefense(){}

void Object::setMp(int mp){}

int Object::getMp(){}

void Object::setHunger(int hun_num){}

void Object::setThirst(int thir_num){}

int Object::getDebuff(){}

int Object::getHunger(){}

int Object::getThirst(){}

int Object::getPoison(){}

int Object::getMoney(){}

void Object::setPoison(int poison){}

int Object::getHealth(){}

int Object::getPrice(){}

int Object::getDamage(){}

int Object::getMpUsed(){}

void Object::setMoney(int money){}
