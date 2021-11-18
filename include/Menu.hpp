#include <iostream>
#include <unistd.h>
using namespace std;

class Menu
{
  public:
  void Intro()
  {
    cout << "Hello Player, Welcome to this singleplayer game called Ancient Lord based on the mythical character of Rama!" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "You will play this game as Lord Rama, a prince who lived in the Kingdom of Ayodhya, son of King Dasharatha. But he was banished to the Firewood Forest unfortunately, where he started living with his wife Sita.\nOne fine day, Ravana, the king of Lanka, invades the Forest for firewood and finds the small house where Rama and Sita were living. He gets mesmerised with Sita's beauty and looks for an opportunity to take her with him. One morning when Rama was out hunting for food, Ravana takes the opportunity and kidnaps Sita. He takes her to his kingdom of Lanka. You come back to discover what had happened.\nYou sit down crying, when Mitra, the keeper of the forest appears..." << endl;
    cout << "-----------------------------------------------" << endl;
    sleep (2);
    cout << "Mitra: Hello Rama, please don't cry. We who live in this Forest are oppressed by Ravana. There has been a prophecy that a Hero will come one day to kill Ravana. We want to destroy Ravana once and for all.\nWe believe in you, please stand up and fight..." << endl;
    cout << "-----------------------------------------------" << endl;
    sleep(1);
    cout << "You: OK Guru, but how can I defeat this fierce demon?" << endl;
    cout << "-----------------------------------------------" << endl;
    sleep(1);
    cout << "Mitra: It will not be easy, but you need to cross this forest till the very end, then cross the seas and finally you will reach Lanka. Along the way, there will be other demons to fight, as you defeat them, you will gain special powers and weapons that will ultimately help you in killing Ravana." << endl;
    cout << "-----------------------------------------------" << endl;
    sleep(2);
  }

  void ShowLevel1()
  {
    cout << "First Level: You make it to the end of the Forest. But there are 2 Rakshasas called Tanka and Banka, who are guarding the passageway to Lanka, each having health of 80 and melee damage of 10, they can randomly either defend or attack you each turn!!" << endl;
  }

};