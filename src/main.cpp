#include <iostream>
#include "/home/runner/TheAncientLord/include/Menu.hpp"
#include "/home/runner/TheAncientLord/include/input.hpp"
#include "/home/runner/TheAncientLord/include/Player.hpp"
using namespace std;


int main(int argc, char *argv[]) {

  // Keyboard inputs, will add depending on what keys are required in our game
  // Keyboard kb;
	// kb.WhiteListKeys({'w', 'a', 's', 'd', ';', 0x0A, 27});

	// while (kb.GetPressedKey() != 0x0A && kb.GetPressedKey() != 27){
	// 	kb.Update();
	// 	std::cout << kb.GetPressedKey();
	// }

  Menu display;
  display.Intro();

  display.ShowLevel1();

  return 0;
}

