#include <iostream>
using namespace std;

class Player
{
  protected:
  int health;
  int mDamage;
  int rDamage;
  int defence;
  string name;

  public:
  void Attack(Player *player1, Player *player2)
  {
    cout << player1->name << " is attacking " << player2->name << endl;
    sleep(1);
    cout << "Right Punch....." << endl;
    sleep(1);
    cout << "Left Punch....." << endl;
    sleep(1);
    player2->health = player2->getHealth() - player1->getMeleeDamage();
  }
  virtual void Defence() = 0;
  virtual void SpecialAbility() = 0;
  int getHealth()
  {
    return health;
  }
  int getMeleeDamage()
  {
    return mDamage;
  }

  int getRangedDamage()
  {
    return rDamage;
  }
  void Heal(int healValue)
  {
    health = health + healValue;
  }
  void setName(string name)
  {
    this->name = name;
  }

  string getName()
  {
    return name;
  }
};

class Hero : public Player
{
  public:
  Hero(int health, int mdamage)
  {
    this->health = health;
    this->mDamage = mDamage;
  }

};

class Rakshasa : public Player
{
  public:
  Rakshasa()
  {
    health = 80;
    mDamage = 10;
  }

};