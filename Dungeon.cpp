#include "Dungeon.h"
#include<cstdlib>
#include<ctime>
using namespace std;

Dungeon::Dungeon()
{

}

void Dungeon::createPlayer()
{
    player=Player("Tatsuya",40,30,150,50,500);
}

void Dungeon::createMap(int isOasis, int isSandstorm)
{
    //room1 common
    vector<Object*> room1Obj;
    room1Obj.push_back(new Item("Short Sword",20,5,10,0,0,0,0,0));
    room1Obj.push_back(new Item("Arm Guard",10,20,20,0,0,0,0,0));
    room1Obj.push_back(new Item("Wand",0,5,10,50,0,0,0,0));
    rooms.push_back(new Room(0,1,room1Obj,"Common Room",3,3,0));

    //room2 forest cow
    vector<Object*> room2Obj;
    room2Obj.push_back(new Monster("Cow",10,10,50,100));
    room2Obj.push_back(new Item("Milk",0,0,0,0,-10,-30,1,0));
    room2Obj.push_back(new Item("Carrot",0,0,10,10,-10,0,0,0));
    rooms.push_back(new Forest(0,2,room2Obj,5,3,0));

    //room3 desert
    vector<Object*> room3Obj;
    room3Obj.push_back(new Monster("Wolf",40,20,150,400));
    room3Obj.push_back(new Item("Chestplate",0,50,20,10,0,0,0,0));
    room3Obj.push_back(new Magic("Fire ball",50,-10));
    room3Obj.push_back(new Item("Wolf meat",0,0,40,0,-30,0,0,0));
    rooms.push_back(new Desert(0,3,room3Obj,3,5,0,0,0));

    //room4 forest
    vector<Object*> room4Obj;
    room4Obj.push_back(new Monster("Tigger",40,20,150,500));
    room4Obj.push_back(new Item("Knife",40,10,0,0,0,0,0,0));
    rooms.push_back(new Forest(0,4,room4Obj,5,3,0));

    //room5 swamp
    vector<Object*> room5Obj;
    room5Obj.push_back(new Monster("Dark Wolf",100,100,500,1000));
    room5Obj.push_back(new Item("Gold Armor",100,200,0,100,0,0,0,0));
    rooms.push_back(new Swamp(0,5,room5Obj,5,5,30));

    //room6 common
    vector<Object*> room6Obj;
    string script1="What do you want to buy?";
    vector<Item> commodity1;
    commodity1.push_back(Item("Beef",0,0,40,0,-40,0,0,100));
    commodity1.push_back(Item("Magic potion",0,0,0,60,0,-20,0,200));
    commodity1.push_back(Item("Long wand",20,0,0,60,0,0,0,300));
    commodity1.push_back(Item("Big sword",50,10,0,0,0,0,0,300));
    room6Obj.push_back(new NPC("Wang Xia sheng",script1,commodity1));
    rooms.push_back(new Room(0,6,room6Obj,"Common Room",5,5,0));

    //room7 common
    vector<Object*> room7Obj;
    room7Obj.push_back(new Monster("Tigger",60,30,160,500));
    room7Obj.push_back(new Item("Knife",50,10,0,0,0,0,0,0));
    room7Obj.push_back(new Item("Water",0,0,0,0,0,-40,0,0));
    room7Obj.push_back(new Item("Tiger meat",0,0,40,0,-30,0,0,0));
    rooms.push_back(new Room(0,7,room7Obj,"Common Room",5,5,0));

    //room8 common
    vector<Object*> room8Obj;
    vector<Item> commodity2;
    commodity2.push_back(Item("Beef",0,0,40,0,-30,0,0,100));
    commodity2.push_back(Item("Water",0,0,0,0,0,-40,0,50));
    commodity2.push_back(Item("Magic potion",0,0,0,60,0,0,0,200));
    commodity2.push_back(Item("Long wand",20,0,0,60,0,0,0,300));
    commodity2.push_back(Item("Milk",0,0,0,0,-10,-30,1,100));
    room8Obj.push_back(new NPC("Thomas",script1,commodity2));
    rooms.push_back(new Room(0,8,room8Obj,"Common Room",5,5,0));

    //room9 forest
    vector<Object*> room9Obj;
    room9Obj.push_back(new Monster("Bear",120,40,200,600));
    room9Obj.push_back(new Item("Foot armor",0,30,0,0,0,0,0,0));
    room9Obj.push_back(new Item("Beer meat",0,0,40,0,-30,0,0,0));
    rooms.push_back(new Forest(0,9,room9Obj,15,10,0));

    //room10 desert
    vector<Object*> room10Obj;
    room10Obj.push_back(new Monster("Wolf",150,50,240,600));
    room10Obj.push_back(new Item("Chestplate",0,100,30,20,0,0,0,0));
    room10Obj.push_back(new Magic("Water ball",150,-50));
    rooms.push_back(new Desert(0,10,room10Obj,10+isSandstorm*5,15+isSandstorm*5,0,0,isSandstorm));

    //room11 swamp
    vector<Object*> room11Obj;
    room11Obj.push_back(new Monster("Giant",100,60,300,1000));
    room11Obj.push_back(new Item("Silver knife",100,50,0,0,0,0,0,0));
    rooms.push_back(new Swamp(0,11,room11Obj,10,10,50));

    //room12 desert
    vector<Object*> room12Obj;
    room12Obj.push_back(new Monster("Wolf",100,100,300,600));
    room12Obj.push_back(new Item("Helmet",0,200,30,20,0,0,0,0));
    rooms.push_back(new Desert(0,12,room12Obj,10,15,0,isOasis,0));

    //room13 forest cow
    vector<Object*> room13Obj;
    room13Obj.push_back(new Monster("Cow",10,10,50,100));
    room13Obj.push_back(new Item("Milk",0,0,0,0,-10,-50,1,0));
    room13Obj.push_back(new Item("Beef",0,0,40,0,-60,0,0,0));
    rooms.push_back(new Forest(0,13,room13Obj,15,10,0));

    //room14 common
    vector<Object*> room14Obj;
    room14Obj.push_back(new Monster("Shaman",200,70,600,1000));
    rooms.push_back(new Room(1,14,room14Obj,"Common Room",15,15,0));

    //connect
    rooms[0]->setRightRoom(rooms[1]);
    rooms[1]->setLeftRoom(rooms[0]);
    rooms[1]->setRightRoom(rooms[3]);
    rooms[1]->setDownRoom(rooms[2]);
    rooms[2]->setLeftRoom(rooms[5]);
    rooms[2]->setDownRoom(rooms[6]);
    rooms[2]->setUpRoom(rooms[1]);
    rooms[3]->setLeftRoom(rooms[1]);
    rooms[3]->setDownRoom(rooms[4]);
    rooms[4]->setUpRoom(rooms[3]);
    rooms[4]->setDownRoom(rooms[7]);
    rooms[5]->setRightRoom(rooms[2]);
    rooms[6]->setUpRoom(rooms[2]);
    rooms[6]->setDownRoom(rooms[8]);
    rooms[7]->setUpRoom(rooms[4]);
    rooms[7]->setDownRoom(rooms[8]);
    rooms[8]->setUpRoom(rooms[6]);
    rooms[8]->setRightRoom(rooms[7]);
    rooms[8]->setDownRoom(rooms[9]);
    rooms[9]->setUpRoom(rooms[8]);
    rooms[9]->setLeftRoom(rooms[10]);
    rooms[9]->setDownRoom(rooms[11]);
    rooms[10]->setRightRoom(rooms[9]);
    rooms[10]->setDownRoom(rooms[13]);
    rooms[11]->setUpRoom(rooms[9]);
    rooms[11]->setRightRoom(rooms[12]);
    rooms[11]->setDownRoom(rooms[13]);
    rooms[12]->setLeftRoom(rooms[11]);
    rooms[13]->setUpRoom(rooms[11]);
    rooms[13]->setLeftRoom(rooms[10]);

}

void Dungeon::handleMovement(Room* nextRoom)
{
    player.setPreviousRoom(player.getCurrentRoom());
    player.setCurrentRoom(nextRoom);
}

void Dungeon::handleEvent(Object* object,int hunger,int thirst,int poison)
{
    object->triggerEvent(&player,hunger,thirst,poison);
}

void Dungeon::startGame()
{
    int isOasis;
    int isSandstorm;
    srand(time(NULL));
    isOasis=rand()%2;
    isSandstorm=1;
    createPlayer();
    createMap(isOasis, isSandstorm);
    player.setCurrentRoom(rooms[0]);
}

void Dungeon::chooseAction(vector<Object*> objects, Room* roomNow, int select)
{
    if(select==1)//first room
    {
        cout<<"Welcome to the dungeon!\n\n";
        cout<<"Welcome to room "<<roomNow->getIndex()<<"!  Room type: "<<roomNow->getRoomState()<<endl;
        cout<<"Please select one gear!\n";
        for(int i=0; i<objects.size(); i++)
        {
            cout<<i+1<<". "<<objects[i]->getName()<<"   Attack: "<<objects[i]->getAttack()<<"    Defense: "<<objects[i]->getDefense()
                <<"   Health: "<<objects[i]->getHealth()<<"   Mp: "<<objects[i]->getMp()<<endl;
        }
        int selection;
        cout<<"\nYour selection: ";
        cin>>selection;
        player.addItem(Item(objects[selection-1]->getName(),objects[selection-1]->getAttack(),objects[selection-1]->getDefense()
                            ,objects[selection-1]->getHealth(),objects[selection-1]->getMp(),objects[selection-1]->getHunger()
                            ,objects[selection-1]->getThirst(),objects[selection-1]->getPoison(),objects[selection-1]->getPrice()));
        player.increaseStates(objects[selection-1]->getAttack(),objects[selection-1]->getDefense(),objects[selection-1]->getHealth()
                              ,objects[selection-1]->getMp(),objects[selection-1]->getPrice(),objects[selection-1]->getHunger(),
                              objects[selection-1]->getThirst(),objects[selection-1]->getPoison());
        //cout<<"h";
    }
    else if(select==2)
    {
        cout<<"Where do you want to go?\n\n";
        if(roomNow->getUpRoom()!=nullptr)
        {
            cout<<"1. Up room\n";
        }
        if(roomNow->getDownRoom()!=nullptr)
        {
            cout<<"2. Down room\n";
        }
        if(roomNow->getRightRoom()!=nullptr)
        {
            cout<<"3. Right room\n";
        }
        if(roomNow->getLeftRoom()!=nullptr)
        {
            cout<<"4. Left room\n";
        }
        int selection;
        cout<<"\nYour selection: ";
        cin>>selection;
        if(selection==1)
        {
            handleMovement(roomNow->getUpRoom());
        }
        else if(selection==2)
        {
            handleMovement(roomNow->getDownRoom());
        }
        else if(selection==3)
        {
            handleMovement(roomNow->getRightRoom());
        }
        else
        {
            handleMovement(roomNow->getLeftRoom());
        }

        cout<<"\nWelcome to room "<<player.getCurrentRoom()->getIndex()<<"!  Room type: "<<player.getCurrentRoom()->getRoomState()<<endl<<endl;
    }
    else if(select==3)
    {
        cout<<"Find Cow do you want to fight with it?\n\n";
        cout<<"1. Yes\n2. No\n\nYour selection: ";
        int selection;
        cin>>selection;
        if(selection==1)
        {
            if(!objects[0]->triggerEvent(&player,roomNow->getRoomHun(),roomNow->getRoomThir(),roomNow->getRoomPoi()))
            {
                player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[0]);
                cout<<"Drop:\n";
                while(!player.getCurrentRoom()->getObjects().empty())
                {
                    int i=0;
                    for(i; i<player.getCurrentRoom()->getObjects().size(); i++)
                    {
                        if(player.getCurrentRoom()->getObjects()[i]->getTag()!="Magic")
                        {
                            cout<<i+1<<". "<<player.getCurrentRoom()->getObjects()[i]->getName()<<"  Attack: "<<player.getCurrentRoom()->getObjects()[i]->getAttack()
                                <<"  Defense: "<<player.getCurrentRoom()->getObjects()[i]->getDefense()<<"  Health: "<<player.getCurrentRoom()->getObjects()[i]->getHealth()
                                <<"  Mp: "<<player.getCurrentRoom()->getObjects()[i]->getMp()<<"  Hunger: "<<player.getCurrentRoom()->getObjects()[i]->getHunger()
                                <<"  Thirst: "<<player.getCurrentRoom()->getObjects()[i]->getThirst()<<endl;
                        }
                        else
                        {
                            cout<<i+1<<". "<<player.getCurrentRoom()->getObjects()[i]->getName()<<"  Damage: "<<player.getCurrentRoom()->getObjects()[i]->getDamage()<<
                                "  Mp: "<<player.getCurrentRoom()->getObjects()[i]->getMpUsed()<<endl;
                        }
                    }
                    cout<<player.getCurrentRoom()->getObjects().size()+1<<". I don't want to pick\n";
                    int sel;
                    cout<<"\nWhich to pick up: ";
                    cin>>sel;
                    if(sel<player.getCurrentRoom()->getObjects().size()+1)
                    {
                        //cout<<"Pick up: "<<sel<<endl;
                        player.addItem(Item(player.getCurrentRoom()->getObjects()[sel-1]->getName(),player.getCurrentRoom()->getObjects()[sel-1]->getAttack(),
                                            player.getCurrentRoom()->getObjects()[sel-1]->getDefense(),player.getCurrentRoom()->getObjects()[sel-1]->getHealth(),
                                            player.getCurrentRoom()->getObjects()[sel-1]->getMp(),player.getCurrentRoom()->getObjects()[sel-1]->getHunger(),
                                            player.getCurrentRoom()->getObjects()[sel-1]->getThirst(),player.getCurrentRoom()->getObjects()[sel-1]->getPoison(),0));
                        //cout<<"finish addItem\n";
                        player.increaseStates(player.getCurrentRoom()->getObjects()[sel-1]->getAttack(),player.getCurrentRoom()->getObjects()[sel-1]->getDefense(),
                                              player.getCurrentRoom()->getObjects()[sel-1]->getHealth(),player.getCurrentRoom()->getObjects()[sel-1]->getMp(),
                                              0,player.getCurrentRoom()->getObjects()[sel-1]->getHunger(),player.getCurrentRoom()->getObjects()[sel-1]->getThirst(),
                                              player.getCurrentRoom()->getObjects()[sel-1]->getPoison());
                        player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[sel-1]);
                        //cout<<"finish erase\n";
                    }
                    else
                    {
                        break;
                    }
                }
                return;
            }
        }
        else
        {
            cout<<"\nWhat do you want to do?\n1. Get some milk\n2. Just go through\n\nYour selection: ";
            cin>>selection;
            if(selection==1)
            {
                player.addItem(Item("Milk",0,0,0,0,-10,-30,1,0));
                player.increaseStates(0,0,0,0,0,-10,-30,1);
            }
            else
            {
                return;
            }
        }
    }
}

bool Dungeon::checkGameLogic()
{
    if(player.checkIsDead())
    {
        return true;
    }
    else if(!player.checkIsDead()&&player.getCurrentRoom()->getIsExit())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Dungeon::runDungeon()
{
    startGame();
    chooseAction(player.getCurrentRoom()->getObjects(),player.getCurrentRoom(),1);
    //player.triggerEvent(&player,0,0,0);//print status
    player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[0]);
    player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[0]);
    player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[0]);

    while(1)
    {
        player.triggerEvent(&player,0,0,0);//print status


        chooseAction(player.getCurrentRoom()->getObjects(),player.getCurrentRoom(),2);//move




        if(player.getCurrentRoom()->getRoomState()=="Desert")
        {
            if(player.getCurrentRoom()->getIsOasis()==1)
            {
                cout<<endl<<"Find Oasis!\n";
                cout<<"replenish thirst.\n";
                player.setThirst(-30);
            }
            //cout<<"sandstorm:  "<<player.getCurrentRoom()->getIsSandstorm()<<"\n\n";
            if(player.getCurrentRoom()->getIsSandstorm()==1)
            {
                cout<<endl<<"Sandstorm!!!!\n";
            }
        }



        if(player.getCurrentRoom()->getObjects().empty())
        {
            cout<<"Here don't have anything.\n";
            continue;
        }
        if(!(player.getCurrentRoom()->getObjects().empty())&&player.getCurrentRoom()->getObjects()[0]->getTag()!="Monster"&&player.getCurrentRoom()->getObjects()[0]->getTag()!="NPC")//re pick
        {
            cout<<"Drop:\n";
            while(!(player.getCurrentRoom()->getObjects().empty()))
            {
                int i=0;
                for(i; i<player.getCurrentRoom()->getObjects().size(); i++)
                {
                    if(player.getCurrentRoom()->getObjects()[i]->getTag()!="Magic")
                    {
                        cout<<i+1<<". "<<player.getCurrentRoom()->getObjects()[i]->getName()<<"  Attack: "<<player.getCurrentRoom()->getObjects()[i]->getAttack()
                            <<"  Defense: "<<player.getCurrentRoom()->getObjects()[i]->getDefense()<<"  Health: "<<player.getCurrentRoom()->getObjects()[i]->getHealth()
                            <<"  Mp: "<<player.getCurrentRoom()->getObjects()[i]->getMp()<<"  Hunger: "<<player.getCurrentRoom()->getObjects()[i]->getHunger()
                            <<"  Thirst: "<<player.getCurrentRoom()->getObjects()[i]->getThirst()<<endl;
                    }
                    else
                    {
                        cout<<i+1<<". "<<player.getCurrentRoom()->getObjects()[i]->getName()<<"  Damage: "<<player.getCurrentRoom()->getObjects()[i]->getDamage()<<
                            "  Mp: "<<player.getCurrentRoom()->getObjects()[i]->getMpUsed()<<endl;
                    }
                }

                cout<<player.getCurrentRoom()->getObjects().size()+1<<". I don't want to pick\n";
                int sel;
                cout<<"\nWhich to pick up: ";
                cin>>sel;
                if(sel<player.getCurrentRoom()->getObjects().size()+1)
                {
                    //cout<<"Pick up: "<<sel<<endl;
                    if(player.getCurrentRoom()->getObjects()[sel-1]->getTag()!="Magic")
                    {


                        player.addItem(Item(player.getCurrentRoom()->getObjects()[sel-1]->getName(),player.getCurrentRoom()->getObjects()[sel-1]->getAttack(),
                                            player.getCurrentRoom()->getObjects()[sel-1]->getDefense(),player.getCurrentRoom()->getObjects()[sel-1]->getHealth(),
                                            player.getCurrentRoom()->getObjects()[sel-1]->getMp(),player.getCurrentRoom()->getObjects()[sel-1]->getHunger(),
                                            player.getCurrentRoom()->getObjects()[sel-1]->getThirst(),player.getCurrentRoom()->getObjects()[sel-1]->getPoison(),0));
                        //cout<<"finish addItem\n";
                        player.increaseStates(player.getCurrentRoom()->getObjects()[sel-1]->getAttack(),player.getCurrentRoom()->getObjects()[sel-1]->getDefense(),
                                              player.getCurrentRoom()->getObjects()[sel-1]->getHealth(),player.getCurrentRoom()->getObjects()[sel-1]->getMp(),
                                              0,player.getCurrentRoom()->getObjects()[sel-1]->getHunger(),player.getCurrentRoom()->getObjects()[sel-1]->getThirst(),
                                              player.getCurrentRoom()->getObjects()[sel-1]->getPoison());
                        player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[sel-1]);
                        //cout<<"finish erase\n";
                    }
                    else
                    {
                        player.addMagic(Magic(player.getCurrentRoom()->getObjects()[sel-1]->getName(),player.getCurrentRoom()->getObjects()[sel-1]->getDamage(),
                                              player.getCurrentRoom()->getObjects()[sel-1]->getMpUsed()));
                        player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[sel-1]);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        else if(player.getCurrentRoom()->getObjects()[0]->getName()=="Cow")//遇到牛
        {
            chooseAction(player.getCurrentRoom()->getObjects(),player.getCurrentRoom(),3);
        }
        else if(player.getCurrentRoom()->getObjects()[0]->getTag()=="NPC")
        {
            cout<<"\nFind NPC: "<<player.getCurrentRoom()->getObjects()[0]->getName()<<"\n\n";
            player.getCurrentRoom()->getObjects()[0]->triggerEvent(&player,0,0,0);
        }
        else//跟一般怪物打架，處理掉落物
        {
            if(!player.getCurrentRoom()->getObjects()[0]->triggerEvent(&player,player.getCurrentRoom()->getRoomHun(),player.getCurrentRoom()->getRoomThir(),player.getCurrentRoom()->getRoomPoi()))
            {

                if(player.getCurrentRoom()->getIsExit())
                {
                    cout<<"You win!\n";
                    break;
                }
                player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[0]);
                cout<<"Drop:\n";
                while(!player.getCurrentRoom()->getObjects().empty())
                {
                    int i=0;
                    for(i; i<player.getCurrentRoom()->getObjects().size(); i++)
                    {
                        if(player.getCurrentRoom()->getObjects()[i]->getTag()!="Magic")
                        {
                            cout<<i+1<<". "<<player.getCurrentRoom()->getObjects()[i]->getName()<<"  Attack: "<<player.getCurrentRoom()->getObjects()[i]->getAttack()
                                <<"  Defense: "<<player.getCurrentRoom()->getObjects()[i]->getDefense()<<"  Health: "<<player.getCurrentRoom()->getObjects()[i]->getHealth()
                                <<"  Mp: "<<player.getCurrentRoom()->getObjects()[i]->getMp()<<"  Hunger: "<<player.getCurrentRoom()->getObjects()[i]->getHunger()
                                <<"  Thirst: "<<player.getCurrentRoom()->getObjects()[i]->getThirst()<<endl;
                        }
                        else
                        {
                            cout<<i+1<<". "<<player.getCurrentRoom()->getObjects()[i]->getName()<<"  Damage: "<<player.getCurrentRoom()->getObjects()[i]->getDamage()<<
                                "  Mp: "<<player.getCurrentRoom()->getObjects()[i]->getMpUsed()<<endl;
                        }

                    }
                    cout<<player.getCurrentRoom()->getObjects().size()+1<<". I don't want to pick\n";
                    int sel;
                    cout<<"\nWhich to pick up: ";
                    cin>>sel;
                    if(sel<player.getCurrentRoom()->getObjects().size()+1)
                    {
                        if(player.getCurrentRoom()->getObjects()[sel-1]->getTag()!="Magic")
                        {


                            player.addItem(Item(player.getCurrentRoom()->getObjects()[sel-1]->getName(),player.getCurrentRoom()->getObjects()[sel-1]->getAttack(),
                                                player.getCurrentRoom()->getObjects()[sel-1]->getDefense(),player.getCurrentRoom()->getObjects()[sel-1]->getHealth(),
                                                player.getCurrentRoom()->getObjects()[sel-1]->getMp(),player.getCurrentRoom()->getObjects()[sel-1]->getHunger(),
                                                player.getCurrentRoom()->getObjects()[sel-1]->getThirst(),player.getCurrentRoom()->getObjects()[sel-1]->getPoison(),0));
                            //cout<<"finish addItem\n";
                            player.increaseStates(player.getCurrentRoom()->getObjects()[sel-1]->getAttack(),player.getCurrentRoom()->getObjects()[sel-1]->getDefense(),
                                                  player.getCurrentRoom()->getObjects()[sel-1]->getHealth(),player.getCurrentRoom()->getObjects()[sel-1]->getMp(),
                                                  0,player.getCurrentRoom()->getObjects()[sel-1]->getHunger(),player.getCurrentRoom()->getObjects()[sel-1]->getThirst(),
                                                  player.getCurrentRoom()->getObjects()[sel-1]->getPoison());
                            player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[sel-1]);
                            //cout<<"finish erase\n";
                        }
                        else
                        {
                            player.addMagic(Magic(player.getCurrentRoom()->getObjects()[sel-1]->getName(),player.getCurrentRoom()->getObjects()[sel-1]->getDamage(),
                                                  player.getCurrentRoom()->getObjects()[sel-1]->getMpUsed()));
                            player.getCurrentRoom()->popObject(player.getCurrentRoom()->getObjects()[sel-1]);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if(player.checkIsDead())
        {
            cout<<"You lose!\n";
            break;
        }

    }

}
