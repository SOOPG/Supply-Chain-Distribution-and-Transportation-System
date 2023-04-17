#include <iostream>
#include "headers/showMainMenu.h"
#include "headers/generateRetailerSites.h"
#include "headers/selectedNonOptimizedRoute.h"
using namespace std;

int main(){

    RetailerSites r;
    r.saveToFile();

    int optionSelected;
    bool programIsRunning=true;
    while (programIsRunning){

        system("CLS");
        cout<<flush;
        r.displayRetailerSitesInMainMenu();
        optionSelected=showMainMenu();

        switch (optionSelected) {
          case 1:
            selectedNonOptimizedRoute(r);
            break;
          case 2:
            cout <<"Tuesday"<<endl;
            system("CLS");
            cout<<flush;
            selectedNonOptimizedRoute(r);
            break;
          case 2:
            system("CLS");
            cout<<flush;
            selectedOptimizedRoute(r);
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
            cout<<""<<endl;
        }
    }
    return 0;
}
