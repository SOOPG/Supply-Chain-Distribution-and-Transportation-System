#include <iostream>
#ifndef showMainMenu_H_Included
#define showMainMenu_H_Included
using namespace std;

int showMainMenu(){

    int option;
    double goodsWeight;

        cout<<"______________________________"<<endl;
        cout<<"Welcome to Supply Chain System"<<endl;
        cout<<"______________________________"<<endl;
        cout<<"Please select your option:"<<endl;
        cout<<"1.Regular(Non-optimized) Route (Min 50KG)"<<endl;
        cout<<"2.Optimized Route (Min 100KG)" <<endl;
        cout<<"3.Greedy Route"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"______________________________"<<endl;
        cout<<"Option:";
        cin>>option;

        /*
        cout<<"Please input your goods weight:"<<endl;
        cin>>goodsWeight;

        cout<<"_____________________"<<endl;
        cout<<"Your Input:";
        cout<<goodsWeight<<"kg"<<endl;
        cout<<"_____________________"<<endl;
        */

    return option;
}

#endif // showMainMenu.h included
