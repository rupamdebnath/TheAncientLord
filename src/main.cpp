#include <iostream>
#include <memory>
#include "/home/runner/TheAncientLord/include/Menu.hpp"
#include "/home/runner/TheAncientLord/include/input.hpp"

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
  }
}

int main(int argc, char *argv[]) {
  // Keyboard inputs, will add depending on what keys are required in our game
  Keyboard kb;
	kb.WhiteListKeys({'w', 'a', 's', 'd', 27});

  Menu display;
  // display.Intro();
  //Level 1 Tataka  
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
      player2->AITurn(player1); 
      player1->HeroAttack(player2);             
      break;

      case 'd':
      player1->Heal(random(0, 10));
      player2->AITurn(player1);   
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
    goto PlayLevel1;
  }
  else
  {  
    WinnerChecker(player1, player2);
  }

  delete player1; 
  delete player2;
  return 0;
}

