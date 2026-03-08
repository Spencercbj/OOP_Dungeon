#include "Item.h"
#include"Object.h"
Item::Item(){}

Item::Item(string name, int attack, int defense, int health, int mp, int hunger, int thirst, int poison, int price):Object(name,"Item")
{
    this->attack=attack;
    this->defense=defense;
    this->health=health;
    this->mp=mp;
    this->hunger=hunger;
    this->thirst=thirst;
    this->poison=poison;
    this->price=price;
}

void Item::setAttack(int attack)
{
    this->attack=attack;
}

void Item::setDefense(int defense)
{
    this->defense=defense;
}

void Item::setHealth(int health)
{
    this->health=health;
}
void Item::setMp(int mp)
{
    this->mp=mp;
}
void Item::setHunger(int hunger)
{
    this->hunger=hunger;
}

void Item::setThirst(int thirst)
{
    this->thirst=thirst;
}

void Item::setPoison(bool poison)
{
    this->poison=poison;
}

void Item::setPrice(int price)
{
    this->price=price;
}

int Item::getAttack()
{
    return attack;
}

int Item::getDefense()
{
    return defense;
}

int Item::getHealth()
{
    return health;
}

int Item::getMp()
{
    return mp;
}

int Item::getHunger()
{
    return hunger;
}

int Item::getThirst()
{
    return thirst;
}

int Item::getPoison()
{
    return poison;
}

int Item::getPrice()
{
    return price;
}

bool Item::triggerEvent(Object* player,int hunger,int thirst,int poison)
{
    player->addItem(Item(getName(),attack,defense,health,mp,hunger,thirst,poison,price));
    player->increaseStates(attack,defense,health,mp,price,hunger,thirst,poison);
    return true;
}
