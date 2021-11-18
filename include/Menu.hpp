#include <iostream>
using namespace std;

class Menu
{
  public:
  void Intro()
  {
    cout << "Hello Player, Welcome to this singleplayer game!" << endl;
    cout << "This is the story of Lord." << endl;
  }

  void ShowLevel1()
  {
    cout << "In the first level level, you have to defeat 2 rakshasas, each having health of 80 and melee damage of 10, they can randomly either defend or attack you each turn!!\nGood Luck!!!" << endl;
  }

};