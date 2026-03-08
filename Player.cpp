#include "Player.h"
#include "Magic.h"
#include "GameCharacter.h"
using namespace std;

Player::Player(){}

Player::Player(string name, int attack, int defense, int health, int mp, int money): GameCharacter(name, "Player", attack, defense, health)
{
    currentRoom=NULL;
    previousRoom=NULL;
    this->mp=mp;
    this->hunger=0;
    this->thirst=0;
    this->poison=0;
    this->money=money;
}

void Player::addItem(Item item)
{
    inventory.push_back(item);
}

void Player::addMagic(Magic magic)
{
    magics.push_back(magic);
}

void Player::increaseStates(int attack, int defense, int health, int mp, int money,int hunger,int thirst,int poison)
{
    //cout<<"increase states!!!\n";
    setAttack(attack);
    setDefense(defense);
    setCurrentHealth(health);
    this->money+=money;
    this->mp+=mp;
    this->hunger+=hunger;
    this->thirst+=thirst;
    if(thirst<30)
    {
        this->setDebuff(0);
    }
    if(poison==1)
    {
        this->poison=0;
    }
}

void Player::changeRoom(Room* room)
{
    previousRoom=currentRoom;
    currentRoom=room;
}

void Player::setCurrentRoom(Room* room)
{
    this->currentRoom=room;
}

void Player::setPreviousRoom(Room* room)
{
    this->previousRoom=room;
}

void Player::setInventory(vector<Item> items)
{
    for(int i=0;i<inventory.size();i++)
    {
        inventory[i]=items[i];
    }
}

void Player::setMp(int mp)
{
    this->mp+=mp;
}

void Player::setHunger(int hun_num)
{
    if(hun_num==0)
    {
        this->hunger=0;
    }
    else if(hunger+hun_num<=30)
    {
        this->hunger+=hun_num;
    }
    else if(hunger+hun_num>30&&hunger<30)
    {
        hunger=30;
    }
    else if(hunger==30)
    {
        this->setCurrentHealth(-10);
    }
}

void Player::setThirst(int thir_num)
{
    if(thir_num==0)
    {
        this->thirst=0;
        this->setDebuff(0);
    }
    else if(thir_num+this->thirst<=30)
    {
        this->thirst+=thir_num;
        this->setDebuff(0);
    }
    else if(thir_num+this->thirst>30&&this->thirst<30)
    {
        thirst=30;
        this->setDebuff(0);
    }
    else if(thirst==30)
    {
        this->setCurrentHealth(-10);
        this->setDebuff(10);//debuff
    }
}

void Player::setPoison(int poi_num)
{
    if(poi_num==0)
    {
        this->poison=0;
    }
    else
    {
        this->poison+=poi_num;
    }
}

void Player::setMoney(int money)
{
    this->money+=money;
}

Room* Player::getCurrentRoom()
{
    return currentRoom;
}

Room* Player::getPreviousRoom()
{
    return previousRoom;
}

vector<Item> Player::getInventory()
{
    return inventory;
}

int Player::getMp()
{
    return mp;
}

int Player::getHunger()
{
    return hunger;
}

int Player::getThirst()
{
    return thirst;
}

int Player::getPoison()
{
    return poison;
}

int Player::getMoney()
{
    return money;
}

vector<Magic> Player::getMagic()
{
    return magics;
}

bool Player::triggerEvent(Object* player,int hunger,int thirst,int poison)
{
    cout<<"\n";
    cout<<"Your status:\n"<<"1. Name: "<<player->getName()<<endl;
    cout<<"2. Attack: "<<player->getAttack()<<endl;
    cout<<"3. Defense: "<<player->getDefense()<<endl;
    cout<<"4. Health: "<<player->getCurrentHealth()<<endl;
    cout<<"5. Mp: "<<player->getMp()<<endl;
    cout<<"6. Debuff: "<<player->getDebuff()<<endl;
    cout<<"7. Hunger: "<<player->getHunger()<<endl;
    cout<<"8. Thirst: "<<player->getThirst()<<endl;
    cout<<"9. Poison: "<<player->getPoison()<<endl;
    cout<<"10.Money:  "<<player->getMoney()<<endl;
    if(!magics.empty())
    {
        for(int i=0;i<magics.size();i++)
        {
            cout<<11+i<<". magic"<<i+1<<": "<<magics[i].getName()<<"  Damage: "<<magics[i].getDamage()<<"  Mp: "<<magics[i].getMpUsed()<<endl;
        }
    }
    cout<<"\n\n";
}
