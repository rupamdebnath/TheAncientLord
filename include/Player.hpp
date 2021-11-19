#include <iostream>
#include <unistd.h>
//#include "/home/runner/TheAncientLord/include/Menu.hpp"
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
  int shield;
  string name;
  bool defenceChecker = false;

  public:
  virtual ~Player(){} //virtual destructor for base class
  
  void HeroAttack(Player *player2)
  {    
    cout << name << " is melee attacking " << player2->name << endl;
    sleep(1);
    cout << "Right Punch.....Pow!..\U0001F44A	\U0001F44A" << endl;
    sleep(1);
    cout << "Left Punch.....Pow!..\U0001F44A	\U0001F44A" << endl;
    sleep(1);
    if (player2->defenceChecker == false)
    {
      cout << player2->name << " : Ow..\U0001F915 Ow..\U0001F915" << endl;
      sleep(1);
      player2->health = player2->getHealth() - getMeleeDamage();
    }
    else if (player2->defenceChecker == true)
    {     
      cout << player2->name << " is defending this turn" << endl;
      sleep(1);
      cout << "Defend from Right.....Thud!! \U0001F646 ..Thud! \U0001F646" << endl;
      sleep(1);
      cout << "Defend from Left.....Thud!! \U0001F646 ..Thud! .\U0001F646" << endl;
      sleep(1);
      player2->health = player2->getHealth() - (getMeleeDamage()-player2->getShield());
      player2->defenceChecker = false;
    }    
  }

  void EnemyAttack(Player *player2)
  {    
    cout << name << " is melee attacking " << player2->name << endl;
    sleep(1);
    cout << "Right Punch from Enemy.....Pow!..\U0001F44A	\U0001F44A" << endl;
    sleep(1);
    cout << "Left Punch from Enemy.....Pow!..\U0001F44A	\U0001F44A" << endl;
    sleep(1);
    player2->health = player2->getHealth() - getMeleeDamage();
  }

  void PlayerStat()
  {
    cout << "==================================" << endl;
    cout << "Health of " << name << " : " << health << endl;
    cout << "Melee Attack power of " << name << " : " << mDamage << endl;
    cout << "Ranged Attack power of " << name << " : " << rDamage << endl;
    cout << "Shielding Power of " << name << " : " << shield << " This value is random for the opponent every new game and this reduces your damage by the said amount." << endl;
    cout << "==================================" << endl;
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
    cout << name << " is healing this turn!! \U0001F49E \U0001F49E" << endl;
    health = health + healValue;
  }
  void TakeDamage(int damagevalue)
  {
    health = health - damagevalue;
  }
  int getShield()
  {
    return shield;
  }

  string getName()
  {
    return name;
  }

  //Enemy AI makes their turn
  void AITurn(Player *player2)
  {
    int rand = random(1,3);
    switch(rand)
    {
      case 1:
      EnemyAttack(player2);
      break;
      
      case 2:
      defenceChecker = true;
      break;

      case 3:
      SpecialAbility();
      break;

    }
  }

  //virtual functions for different abilities based on characters
  virtual void SpecialAbility() = 0;
  virtual void SpecialAbility(Player *player) = 0;
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
  ~Hero()
  {
    cout << "Sorry, you are dead, you can reset the game and try again" << endl;
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
  void SpecialAbility(){}
  void SpecialAbility(Player *player){}

};

class Tataka : public Player
{
  public:
  Tataka(string name)
  {
    health = 100;
    mDamage = 35;
    rDamage = 0;
    shield = random(0, 10);
    this->name = name;
  }
  void SpecialAbility()
  {
    cout << "Tataka drinks nearby deer's blood to restore health in the range of 5 to 10.." << endl;
    int rand = random(5,10);
    Heal(rand);
  }
  void SpecialAbility(Player *player){}

  ~Tataka()
  {
    cout << "Congratulations, You have successfully killed Tataka!!" << endl;
    cout << "You have received the boomerang weapon now, you can use this as a ranged weapon, there is a 50% probability that your opponent will miss next turn." << endl;
  }

};