#ifndef MAGIC_H_INCLUDED
#define MAGIC_H_INCLUDED
#include"Item.h"
#include"Object.h"

using namespace std;

class Magic: public Object
{
private:
    int damage;
    //string magicName;
    int mpUsed;
public:
    Magic();
    Magic(string, int, int);
    bool triggerEvent(Object*,int,int,int);
    void setDamage(int);
    void setMpUsed(int);
    int getDamage();
    int getMpUsed();
};


#endif // MAGIC_H_INCLUDED
