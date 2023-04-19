#include <iostream>
#include "headers/showMainMenu.h"
#include "headers/generateRetailerSites.h"
#include "headers/selectedNonOptimizedRoute.h"
#include "headers/selectedOptimizedRoute.h"
#include "headers/selectedGreedyRoute.h"
using namespace std;

int main(){

    //Constructor
    RetailerSites r;
    r.saveToFile();
    OptimizedRoute optimizedRoute;
    GreedyRoute greedyRoute;

    int optionSelected;
    bool programIsRunning=true;

    //program is running
    while (programIsRunning){

        system("CLS");
        cout<<flush;
        r.displayRetailerSitesInMainMenu();
        optionSelected=showMainMenu();

        switch (optionSelected) {
          case 1:
            system("CLS");
            cout<<flush;
            selectedNonOptimizedRoute(r);
            break;
          case 2:
            system("CLS");
            cout<<flush;
            selectedOptimizedRoute(r, optimizedRoute);
            break;
          case 3:
            system("CLS");
            cout<<flush;
            selectedGreedyRoute(r, greedyRoute, optimizedRoute);
            break;
          case 4:
            cout <<"Exiting Program..."<<endl;
            programIsRunning=false;
            break;
          default:
              if (optionSelected<1 || optionSelected>4)
                //if user inputs other than 1,2,3,4
            throw std::invalid_argument("Option input only between 1-4");
            cout<<""<<endl;
        }
    }
    return 0;
}
