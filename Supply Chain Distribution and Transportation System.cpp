#include <iostream>
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
