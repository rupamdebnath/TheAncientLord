#include <iostream>
#include <unistd.h>
using namespace std;

//writing a randoim function for the abilities of characters
int random(int min, int max) //range : [min, max]
{
  bool first = true;
  if (first) 
  {  
    srand(time(NULL)); //seeding for the first time only!
    first = false;
  }
  int _value = min + rand() % (( max + 1 ) - min);
  return _value;
}

//The Base class Player from which all the other characters will be inherited
class Player
{
  protected:
  int health;
  int mDamage;
  int rDamage; 
  int defence;
  string name;

  public:
  virtual ~Player(){} //virtual destructor for base class
  
  void Attack(Player *player2)
  {
    cout << name << " is melee attacking " << player2->name << endl;
    sleep(1);
    cout << "Right Punch.....Pow!..\U0001F44A	\U0001F44A" << endl;
    sleep(1);
    cout << "Left Punch.....Pow!..\U0001F44A	\U0001F44A" << endl;
    sleep(1);
    cout << player2->name << " : Ow.. Ow.." << endl;
    sleep(1);
    player2->health = player2->getHealth() - getMeleeDamage();
  }
  void PlayerStat()
  {
    cout << "Health of " << name << " : " << health;
    cout << "Melee Attack power of " << name << " : " << mDamage;
    cout << "Ranged Attack power of " << name << " : " << rDamage;
  }

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
  void TakeDamage(int damagevalue)
  {
    health = health - damagevalue;
  }

  string getName()
  {
    return name;
  }

  //virtual functions for different abilities based on characters
  void Defend(Player *player2)
  {
    cout << name << " is attacking but " << player2->name << "is defending..." <<endl;
    sleep(1);
    cout << "Defend from Right.....Thud!! \U0001F646 ..Thud! \U0001F646" << endl;
    sleep(1);
    cout << "Defend from Left.....Thud!! \U0001F646 ..Thud! .\U0001F646" << endl;
    sleep(1);
  }
  virtual void SpecialAbility() = 0;
  //virtual void Heal() = 0;
};

class Hero : public Player
{
  public:
  Hero(string name, int health, int mDamage)
  {
    this->name = name;
    this->health = health;
    this->mDamage = mDamage;
  }
  void SpecialAbility(){}
  void SpecialAbility(Player *player)
  {
    int spDamage = random(40,70);
    cout << "Rama uses his Bow and Arrow to strike lighting from the skies...\U0001F3F9 \U0001F329 \U0001F329 \U0001F329" << endl;
    player->TakeDamage(spDamage);
  }
};

class Rakshasa : public Player
{
  public:
  Rakshasa(string name)
  {
    health = 80;
    mDamage = 10;
    this->name = name;
  }

};

class Tataka : public Player
{
  public:
  Tataka(string name)
  {
    health = 100;
    mDamage = 20;
    this->name = name;
  }
  void SpecialAbility()
  {
    cout << "Tataka is drinks nearby deer's blood to restore health in the range of 5 to 10.." << endl;
    int rand = random(5,10);
    Heal(rand);
  }

};