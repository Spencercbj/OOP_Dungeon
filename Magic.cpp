 #include"Magic.h"

 using namespace std;

 Magic::Magic(){}

 Magic::Magic(string magicName, int damage, int mpUsed):Object(magicName,"Magic")
 {
     this->damage=damage;
     this->mpUsed=mpUsed;
 }

 void Magic::setDamage(int damage)
 {
     this->damage=damage;
 }

 void Magic::setMpUsed(int mp)
 {
     this->mpUsed=mp;
 }

 int Magic::getDamage()
 {
     return damage;
 }

 int Magic::getMpUsed()
 {
     return mpUsed;
 }

 bool Magic::triggerEvent(Object* player,int hunger,int thirst,int poison)
 {
    player->addMagic(Magic(getName(),damage,mpUsed));
    return true;
 }
