#include <iostream>
#include <memory>
#include <Menu.hpp>
#include <input.hpp>
//#include "/home/runner/TheAncientLord/include/Level.hpp"

using namespace std;
char c;

void WinnerChecker(Player *player1, Player *player2)
{
  if (player1->getHealth() < 1)
  {
    delete player1;
  }
  else if (player2->getHealth() < 1)
  {
    delete player2;
    // player1->Reset();
  }
}

int main(int argc, char *argv[]) {
  // Keyboard inputs, will add depending on what keys are required in our game
  Keyboard kb;
	kb.WhiteListKeys({'w', 'a', 's', 'd', 27});

  Menu display;
  // display.Intro();
  //Level 1 Tataka 
  /* 
  Player *player2 = new Tataka("Tataka");  
  display.ShowLevel1(); 
  PlayLevel1:
  do
  {
    PlayScene:
    player2->PlayerStat();
    display.ShowHeroTurn();
    kb.Update();
    //std::cout << kb.GetPressedKey();
    switch(kb.GetPressedKey())
    {
      case 'a':
      player2->AITurn(player1, 3); 
      player1->HeroAttack(player2);             
      break;

      case 'd':
      player1->Heal(random(0, 10));
      player2->AITurn(player1, 3);   
      break;

      case 27:
      break;
      
      default:
      cout << "Invalid selection, either you do not have any related weapons/abilities or you have simply typed the wrong key! Please try again" << endl;
      goto PlayScene;
      break;
    }      
  }
  while (kb.GetPressedKey() != 27 && player1->getHealth() > 0 && player2->getHealth() > 0);
  if (player1->getHealth() < 1)
  {
    cout << "Oops you died. Do you want to retry this level? (y/n)\n" << endl;
    cin >> c;
    if (c == 'y')
    {
      player1->Reset();
      player2->Reset();
      goto PlayLevel1;
    }
  }
  else
  {  
    WinnerChecker(player1, player2);
  }
  */
  //Level 2 Banka and Danka
  /*
  Player * player3 = new Rakshasa("Tanka", 15, 80, 20);
  Player * player4 = new Rakshasa("Banka", 15, 80, 20);
  player1->LevelUp(150, 35, 0, 0);
  display.ShowLevel2();
  
  PlayLevel2:
  do
  {
    PlayScene2:
    player3->PlayerStat();
    player4->PlayerStat();
    display.ShowHeroTurn();
    kb.Update();
    //std::cout << kb.GetPressedKey();
    switch(kb.GetPressedKey())
    {
      case 'a':
      player3->getHealth() > 0? player3->AITurn(player1, 2) : null;
      player4->getHealth() > 0? player4->AITurn(player1, 2) : null;
      player3->getHealth() > 0? player1->HeroAttack(player3) : null; 
      player4->getHealth() > 0? player1->HeroAttack(player4) : null;              
      break;

      case 'd':
      player1->Heal(random(10, 20));
      player3->getHealth() > 0? player3->AITurn(player1, 2) : null;
      player4->getHealth() > 0? player4->AITurn(player1, 2) : null;
      break;

      case 27:
      break;

      default:
      cout << "Invalid selection, either you do not have any related weapons/abilities or you have simply typed the wrong key! Please try again" << endl;
      goto PlayScene2;
      break;
    }      
  }
  while (kb.GetPressedKey() != 27 && player1->getHealth() > 0 && player3->getHealth() > 0 && player4->getHealth() > 0);
  if (player1->getHealth() < 1)
  {
    cout << "Oops you died. Do you want to retry this level? (y/n)\n" << endl;
    cin >> c;
    if (c == 'y')
    {
      player1->Reset();
      player3->Reset();
      player4->Reset();
      goto PlayLevel2;
    }
  }
  else
  {  
    WinnerChecker(player1, player3);
    WinnerChecker(player1, player4);  
    if (player3->getHealth() < 1 && player4->getHealth() < 1) 
    cout << "You have received the Sword weapon \U0001F5E1, now you can use heavy damage!!" << endl;
  }
  */
  //Level 3 Three enemies
  Player * player5 = new Rakshasa("Marichi", 15, 80, 20);
  Player * player6 = new Rakshasa("Danava", 15, 80, 20);
  Player * player7 = new Rakshasa("Dadhichi", 15, 80, 20);
  player1->LevelUp(150, 35, 0, 0);
  display.ShowLevel3();
  
  PlayLevel3:
  do
  {
    PlayScene3:
    player5->PlayerStat();
    player6->PlayerStat();
    player7->PlayerStat();
    display.ShowHeroTurn();
    kb.Update();
    //std::cout << kb.GetPressedKey();
    switch(kb.GetPressedKey())
    {
      case 'a':
      player5->getHealth() > 0? void(player5->AITurn(player1, 2)) : void(); 
      player6->getHealth() > 0? void(player6->AITurn(player1, 2)) : void();
      player7->getHealth() > 0? void(player7->AITurn(player1, 2)) : void();
      player5->getHealth() > 0? void(player1->HeroAttack(player5)): void(); 
      player6->getHealth() > 0? void(player1->HeroAttack(player6)): void();
      player7->getHealth() > 0? void(player1->HeroAttack(player7)): void();       
      break;

      case 'd':
      player1->Heal(random(20, 30));
      player6->getHealth() > 0? void(player6->AITurn(player1, 2)): void();
      player5->getHealth() > 0? void(player5->AITurn(player1, 2)): void();
      player7->getHealth() > 0? void(player7->AITurn(player1, 2)): void(); 
      break;

      case 27:
      break;

      default:
      cout << "Invalid selection, either you do not have any related weapons/abilities or you have simply typed the wrong key! Please try again" << endl;
      goto PlayScene3;
      break;
    }      
  }
  while (kb.GetPressedKey() != 27 && player1->getHealth() > 0 && player5->getHealth() > 0 && player6->getHealth() > 0 && player7->getHealth() > 0);
  if (player1->getHealth() < 1)
  {
    cout << "Oops you died. Do you want to retry this level? (y/n)\n" << endl;
    cin >> c;
    if (c == 'y')
    {
      player1->Reset();
      player5->Reset();
      player6->Reset();
      player7->Reset();
      goto PlayLevel3;
    }
  }
  else
  {  
    WinnerChecker(player1, player5);
    WinnerChecker(player1, player6);
    WinnerChecker(player1, player7);
    if (player5->getHealth() < 1 && player6->getHealth() < 1 && player7->getHealth() < 1) 
    cout << "You have received the Shield weapon \U0001F5E1, now you can block damage!!" << endl;
  }
  
  delete player1; 
  // delete player2;
  return 0;
}

