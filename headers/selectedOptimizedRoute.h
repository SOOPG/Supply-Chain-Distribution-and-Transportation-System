#ifndef SELECTEDOPTIMIZEDPATH_H_INCLUDED
#define SELECTEDOPTIMIZEDPATH_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include "generateRetailerSites.h"

using namespace std;

class OptimizedRoute {
public:
    string locations[10];
    double goodsWeight[10];
    int distancesFromSupplierHQ[10];
    int retailerConnectedToDistance[10];
    string retailerConnectedTo[10];
    int totalDistanceTravelled=0;
    string RetailerTravelled;

};

int calculateOptimizedRoute(RetailerSites retailerBeforeFilterRoute) {
    cout << left << setw(20) << "Location"
         << setw(20) << "Weight (kg)"
         << setw(30) << "Distance from HQ (km)"
         << setw(30) << "Retailer Connected:"
         << "Distance (km):" << endl;

    int first=0;
    int totalRetailDistanceTravel=0;
    int totalDistanceTraveledFromHQ=0;

    for (int i = 0; i < 10; i++) {
        if (retailerBeforeFilterRoute.goodsWeight[i] >= 100 && retailerBeforeFilterRoute.distancesFromSupplierHQ[i] <= 30) {
            cout << left << setw(23) << retailerBeforeFilterRoute.locations[i]
                 << setw(25) << retailerBeforeFilterRoute.goodsWeight[i]
                 << setw(30) << retailerBeforeFilterRoute.distancesFromSupplierHQ[i]
                 << setw(27) << retailerBeforeFilterRoute.retailerConnectedTo[i]
                 << retailerBeforeFilterRoute.retailerConnectedToDistance[i] << endl;
                 //Check if its first retail, if so add distance direct from HQ
                if(first==0){
                    totalDistanceTraveledFromHQ+=retailerBeforeFilterRoute.distancesFromSupplierHQ[i];
                    first++;
                }
        }
    }
    cout << "______________________________________________"  << endl;
    cout << "        Each Retail-to-Retail Distance        "  << endl;
    cout << "     Retailer 1 to Retailer 2   =  5  km      "  << endl;
    cout << "     Retailer 1 to Retailer 3   =  15 km      "  << endl;
    cout << "     Retailer 2 to Retailer 3   =  10 km      "  << endl;
    cout << "     Retailer 3 to Retailer 10  =  90 km      "  << endl;
    cout << "     Retailer 2 to Retailer 10  = 100 km      "  << endl;
    cout << "     Retailer 1 to Retailer 10  = 105 km      "  << endl;
    cout << "  If Only 1 Retail on List Please Type In 0   "  << endl;
    cout << "______________________________________________"  << endl;
    cout << "Enter your retail-to-retail route distance (km): ";
    cin>>totalRetailDistanceTravel;

    cout << "Total Retail-to-Retail Distance Traveled: ";
    cout<<totalRetailDistanceTravel<< " km" << endl;
    //Actual Route
    totalDistanceTraveledFromHQ=totalRetailDistanceTravel+totalDistanceTraveledFromHQ;
    cout << "Total Route Distance Traveled: ";
    cout <<totalDistanceTraveledFromHQ<< " km" << endl;
    cout<<"_______________________________________________________________"<<endl;
    return totalDistanceTraveledFromHQ;
}

void selectedOptimizedRoute(RetailerSites& r, OptimizedRoute& optimizedRoute) {

    optimizedRoute.totalDistanceTravelled=calculateOptimizedRoute(r); // add this line to display the retailer sites

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

#endif // SELECTEDOPTIMIZEDPATH_H_INCLUDED
