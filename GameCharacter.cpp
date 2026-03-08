#include "GameCharacter.h"

using namespace std;

GameCharacter::GameCharacter(){}

GameCharacter::GameCharacter(string name, string tag, int attack, int defense, int health):Object(name,tag)
{
    this->attack=attack;
    this->defense=defense;
    this->maxHealth=health;
    this->currentHealth=health;
}

void GameCharacter::setMaxHealth(int maxHealth)
{
    this->maxHealth=maxHealth;
}

void GameCharacter::setAttack(int attack)
{
    this->attack+=attack;
}

void GameCharacter::setCurrentHealth(int health)
{
    this->currentHealth+=health;
}

void GameCharacter::setDefense(int defense)
{
    this->defense+=defense;
}

void GameCharacter::setDebuff(int debuff)
{
    if(debuff==0)
    {
        this->debuff=0;
    }
    else
    {
        this->debuff=debuff;
    }
}

int GameCharacter::getAttack()
{
    return attack-debuff;
}

int GameCharacter::getCurrentHealth()
{
    return currentHealth;
}

int GameCharacter::getDefense()
{
    return defense;
}

int GameCharacter::getMaxHealth()
{
    return maxHealth;
}

int GameCharacter::getDebuff()
{
    return debuff;
}

bool GameCharacter::checkIsDead()
{
    if(currentHealth<=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void GameCharacter::takeDamage(int damage)
{
    if(damage>defense)
    {
        currentHealth=currentHealth-(-defense+damage);
    }
}
