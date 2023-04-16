#include <iostream>
#ifndef SHOWMAINMENU_H_INCLUDED
#define SHOWMAINMENU_H_INCLUDED
using namespace std;

int showMainMenu(){

    int option;
    double goodsWeightInput;

        cout<<"_________________________________________"<<endl;
        cout<<"Welcome to Supply Chain System"<<endl;
        cout<<"_________________________________________"<<endl;
        cout<<"Please select your option:"<<endl;
        cout<<"1.Regular(Non-optimized) Route (Min 50KG)"<<endl;
        cout<<"2.Optimized Route (Min 100KG)" <<endl;
        cout<<"3.Greedy Route (No Minimum Weight)"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"_________________________________________"<<endl;
        cout<<"Option:";
        cin>>option;

    return option;
}

#endif // SHOWMAINMENU_H_INCLUDED
