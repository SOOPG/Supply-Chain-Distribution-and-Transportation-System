#ifndef SELECTEDNONOPTIMIZEDROUTE_H_INCLUDED
#define SELECTEDNONOPTIMIZEDROUTE_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "generateRetailerSites.h"
using namespace std;

void selectedNonOptimizedRoute(RetailerSites r){

    RetailerSites retailerList = r;
    char routeApproval;
    system("CLS");
    cout<<flush;

    retailerList.displayRetailerSites(1);

    cout<<"____________________________________________________________"<<endl;
    cout<<"Do you wish to approve this route to be used by driver?[Y/N]"<<endl;
    cout<<"Enter 'Y' or 'y' for Confirm & 'N' or 'n' for Decline"<<endl;
    cin>>routeApproval;
    cout<<"____________________________________________________________"<<endl;

    if(routeApproval=='Y' || routeApproval=='y'){
        cout<< "Route Confirmed!";
        system ("PAUSE");
    }else if (routeApproval=='N' || routeApproval=='n'){
        cout<< "Route Declined!";
        system ("PAUSE");
    }else{
    throw
    std::invalid_argument("Please Confirm with key 'Y' or Decline with key'N'");
    system ("PAUSE");}

}

#endif // SELECTEDNONOPTIMIZEDROUTE_H_INCLUDED
