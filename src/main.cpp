#include <iostream>
#include <memory>
#include "/home/runner/TheAncientLord/include/Menu.hpp"
#include "/home/runner/TheAncientLord/include/input.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  // Keyboard inputs, will add depending on what keys are required in our game
  Keyboard kb;
	kb.WhiteListKeys({'w', 'a', 's', 'd', 27});

  Menu display;
  display.Intro();

  //Level 1 Tataka  
  Player *player2 = new Tataka("Tataka");  
  display.ShowLevel1();

  display.ShowHeroTurn();
  // cout << "Your turn:" << endl;

  while (kb.GetPressedKey() != 27)
  {
    kb.Update();
    //std::cout << kb.GetPressedKey();
    switch(kb.GetPressedKey())
    {
      case 'a':
      player1->Attack(player2);
      break;

      case 'd':
      player1->Defend(player2);
      break;
    }
  } 

  return 0;
}

