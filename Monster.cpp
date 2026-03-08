#include "Monster.h"
#include"Object.h"
#include "Player.h"
#include "Magic.h"
using namespace std;

Monster::Monster(){}

Monster::Monster(string name, int attack, int defense, int health,int money_drop):GameCharacter(name, "Monster", attack, defense, health)
{
    this->money_drop=money_drop;
}

void Monster::setMoney(int money)
{
    this->money_drop=money;
}

int Monster::getMoney()
{
    return money_drop;
}

bool Monster::triggerEvent(Object* player,int hunger,int thirst,int poison)
{
    cout<<"Monster: "<<this->getName()<<"  Attack: "<<this->getAttack()<<"  Defense: "
    <<this->getDefense()<<"  Health: "<<this->getMaxHealth()<<endl;
    while(1)
    {
        //show player status per round
        player->triggerEvent(player,0,0,0);
        cout<<endl;

        //player attack
        int attackMethod;
        cout<<"Your turn!\nSelect attack method:\n1. Physic\n2. Magic\n\nYour selection: ";
        cin>>attackMethod;
        if(attackMethod==1)//physic attack
        {
            this->takeDamage(player->getAttack());
            cout<<"Cause ";
            if(player->getAttack()-this->getDefense()>0)
            {
                cout<<player->getAttack()-this->getDefense();
            }
            else
            {
                cout<<0;
            }
            cout<<" damage!\n\n";

        }
        else//magic attack
        {
            if(player->getMagic().empty())
            {
                cout<<"You don't have magic.\n";
                continue;
            }
            else
            {
                cout<<"Choose magic: \n";
                for(int i=0;i<player->getMagic().size();i++)
                {
                    cout<<i+1<<". "<<player->getMagic()[i].getName()<<" Damage: "<<player->getMagic()[i].getDamage()<<" MpUsed: "
                    <<player->getMagic()[i].getMpUsed()<<endl;
                }
                cout<<"Your selection: ";
                int magic_num;
                cin>>magic_num;
                if(player->getMagic()[magic_num-1].getMpUsed()+player->getMp()<0)
                {
                    cout<<"You don't have enough mp.\n";
                    continue;
                }
                else
                {
                    this->takeDamage(player->getMagic()[magic_num-1].getDamage());
                    player->setMp(player->getMagic()[magic_num-1].getMpUsed());
                    cout<<"Cause ";
                    if (player->getMagic()[magic_num-1].getDamage()-this->getDefense()>0)
                    {
                        cout<<player->getMagic()[magic_num-1].getDamage()-this->getDefense();
                    }
                    else
                    {
                        cout<<0;
                    }
                    cout<<" damage!\n\n";
                }
            }
        }
        /*地形效果*/
        player->setHunger(hunger);
        player->setThirst(thirst);
        if(poison>0)
        {
            player->setCurrentHealth(-poison);
            player->setPoison(poison);
        }
        else
        {
            if(player->getPoison()>0)
            {
                player->setCurrentHealth(-player->getPoison());
            }
        }

        //check if win
        if(this->checkIsDead())
        {
            cout<<"Kill the monster!\n";
            player->setMoney(this->getMoney());
            return false;//player win the monster
        }
        cout<<this->getName()<<" remain health: "<<this->getCurrentHealth()<<endl;
        //monster attack
        cout<<"Monster turn!\n";
        player->takeDamage(this->getAttack());
        cout<<"Cause ";
        if (this->getAttack()-player->getDefense()>0)
        {
            cout<<this->getAttack()-player->getDefense();
        }
        else
        {
            cout<<0;
        }
        cout<<" damage!\n\n";

        //check if continue
        if(player->checkIsDead())
        {
            cout<<"You are dead!\n";
            return true;//player die end game
        }

    }
}
