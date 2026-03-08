#include "NPC.h"
#include<vector>
#include"Item.h"
using namespace std;

NPC::NPC(){}

NPC::NPC(string name, string script, vector<Item> items):GameCharacter(name, "NPC",0,0,0)
{
    this->script=script;
    for(int i=0;i<items.size();i++)
    {
        this->commodity.push_back(items[i]);
    }
}

void NPC::listCommodity()
{
    for(int i=0;i<commodity.size();i++)
    {
        cout<<i+1<<". "<<commodity[i].getName()<<"  Price: "<<commodity[i].getPrice()<<"  Attack: "<<commodity[i].getAttack()
        <<"  Defense: "<<commodity[i].getDefense()<<"  Health: "<<commodity[i].getHealth()<<"  Mp: "<<commodity[i].getMp()<<"  Hunger: "
        <<commodity[i].getHunger()<<"  Thirst: "<<commodity[i].getThirst()<<endl;

    }
}

bool NPC::triggerEvent(Object* player,int hunger,int thirst,int poison)
{
    while(!commodity.empty())
    {
        cout<<"Commodity list:\n";
        listCommodity();
        cout<<commodity.size()+1<<". I don't want to buy.\n\n";
        cout<<"Your selection: ";
        int commodity_num;
        cin>>commodity_num;
        if(commodity_num==commodity.size()+1)
        {
            return true;
        }
        if(commodity[commodity_num-1].getPrice()>player->getMoney())
        {
            cout<<"You don't have enough money.\n";
            continue;
        }
        else
        {
            player->addItem(commodity[commodity_num-1]);
            player->increaseStates(commodity[commodity_num-1].getAttack(),commodity[commodity_num-1].getDefense(),commodity[commodity_num-1].getHealth()
                                   ,commodity[commodity_num-1].getMp(),-(commodity[commodity_num-1].getPrice()),commodity[commodity_num-1].getHunger()
                                   ,commodity[commodity_num-1].getThirst(),commodity[commodity_num-1].getPoison());
            //cout<<"Price: "<<commodity[commodity_num-1].getPrice()<<endl;
            //player->setMoney(-commodity[commodity_num-1].getPrice());
            player->triggerEvent(player,0,0,0);
            commodity.erase(commodity.begin()+commodity_num-1,commodity.begin()+commodity_num);
        }
    }

    return true;
}

void NPC::setScript(string script)
{
    this->script=script;
}

void NPC::setCommodity(vector<Item> items)
{
    for(int i=0;i<items.size();i++)
    {
        this->commodity.push_back(items[i]);
    }
}

string NPC::getScript()
{
    return script;
}

vector<Item> NPC::getCommodity()
{
    return commodity;
}
