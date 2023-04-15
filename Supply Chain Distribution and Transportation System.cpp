#include <iostream>
#include "headers/showMainMenu.h"
using namespace std;

int main(){

    int optionSelected;
    bool programIsRunning=true;
    while (programIsRunning){
        optionSelected=showMainMenu();

        switch (optionSelected) {
          case 1:
            cout <<"Monday"<<endl;
            break;
          case 2:
            cout <<"Tuesday"<<endl;
            break;
          case 3:
            cout <<"Wednesday"<<endl;
            break;
          case 4:
            cout <<"Exiting Program..."<<endl;
            programIsRunning=false;
            break;
          default:
              if (optionSelected<1 || optionSelected>4)
            throw std::invalid_argument("Option input only between 1-4");
        }
    }
    return 0;
}
