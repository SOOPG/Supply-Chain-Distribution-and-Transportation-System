#ifndef SELECTEDGREEDYROUTE_H_INCLUDED
#define SELECTEDGREEDYROUTE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include "generateRetailerSites.h"
#include "selectedOptimizedRoute.h"

class GreedyRoute {
public:
    string locations[10];
    double goodsWeight[10];
    int distancesFromSupplierHQ[10];
    int retailerConnectedToDistance[10];
    string retailerConnectedTo[10];
    int totalDistanceTravelled=0;
    string RetailerTravelled;

};

int displayGreedyRoute(RetailerSites retailerBeforeFilterRoute) {

}

void selectedGreedyRoute(RetailerSites& r, GreedyRoute& greedyRoute) {

    r.displayRetailerSitesInMainMenu();

    char routeApproval;
    cout << "Do you wish to approve this route to be used by driver?[Y/N]" << endl;
    cout << "Enter 'Y' or 'y' for Confirm & 'N' or 'n' for Decline" << endl;
    cin >> routeApproval;

    if(routeApproval=='Y' || routeApproval=='y'){
        cout<< "Route Confirmed!"<<endl;
        system ("PAUSE");
    }else if (routeApproval=='N' || routeApproval=='n'){
        cout<< "Route Declined!"<<endl;
        system ("PAUSE");
    }else{
    throw
    std::invalid_argument("Please Confirm with key 'Y' or Decline with key'N'");
    system ("PAUSE");}
}

#endif // SELECTEDGREEDYROUTE_H_INCLUDED
