#ifndef SELECTEDOPTIMIZEDPATH_H_INCLUDED
#define SELECTEDOPTIMIZEDPATH_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "generateRetailerSites.h"
using namespace std;

void selectedOptimizedRoute(RetailerSites r){

    RetailerSites retailerList = r;
    char routeApproval;
    system("CLS");
    cout<<flush;

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
    }

}

#endif // SELECTEDOPTIMIZEDPATH_H_INCLUDED
