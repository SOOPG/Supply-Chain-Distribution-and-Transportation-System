#ifndef SELECTEDGREEDYROUTE_H_INCLUDED
#define SELECTEDGREEDYROUTE_H_INCLUDED

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include "generateRetailerSites.h"
#include "selectedOptimizedRoute.h"

class GreedyRoute {
public:
    int totalDistanceTravelledGreedy;

};

int calculateGreedyRoute(RetailerSites retailerBeforeFilterRoute) {

       cout << left << setw(20) << "Location"
         << setw(20) << "Weight (kg)"
         << setw(30) << "Distance from HQ (km)"
         << "Cost Effectiveness"<< endl;

    double costEffectiveness[10];
    int locationToDelete1;
    int locationToDelete2;
    int totalRetailDistanceTravel=0;
    int totalDistanceTravelledFromHQ=0;

    for (int i = 0; i < 10; i++) {
        costEffectiveness[i]=retailerBeforeFilterRoute.goodsWeight[i]/retailerBeforeFilterRoute.distancesFromSupplierHQ[i];
    }

    // Find the two lowest cost-effectiveness values
    double minCostEffectiveness1 = 1e9, minCostEffectiveness2 = 1e9;
    for (int i = 0; i < 10; i++) {
        if (costEffectiveness[i] < minCostEffectiveness1) {
            minCostEffectiveness2 = minCostEffectiveness1;
            minCostEffectiveness1 = costEffectiveness[i];
        } else if (costEffectiveness[i] < minCostEffectiveness2) {
            minCostEffectiveness2 = costEffectiveness[i];
        }
    }

    // Get the indices of the two lowest cost-effectiveness values
    for (int i = 0; i < 10; i++) {
        if (retailerBeforeFilterRoute.goodsWeight[i]/retailerBeforeFilterRoute.distancesFromSupplierHQ[i] == minCostEffectiveness1) {
            locationToDelete1 = i;
        } else if (retailerBeforeFilterRoute.goodsWeight[i]/retailerBeforeFilterRoute.distancesFromSupplierHQ[i] == minCostEffectiveness2) {
            locationToDelete2 = i;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (i != locationToDelete1 && i != locationToDelete2) {
            cout << left << setw(23) << retailerBeforeFilterRoute.locations[i]
                 << setw(25) << retailerBeforeFilterRoute.goodsWeight[i]
                 << setw(30) << retailerBeforeFilterRoute.distancesFromSupplierHQ[i]
                 << setw(27) << setprecision(3) << costEffectiveness[i]<< endl;
        }
    }

    cout << "Max 8 Location! Automatically deleting the two low cost-effective locations!" << endl;

    cout << "______________________________________________"  << endl;
    cout << "        Each Retail-to-Retail Distance        "  << endl;
    cout << "             FROM(ROW) TO(COLUMN)             "  << endl;
    cout << "     1. {15,0,5,15,30,30,55,70,75,85,120}     "  << endl;
    cout << "     2. {20,5,0,10,30,25,50,65,70,80,100}     "  << endl;
    cout << "     3. {30,15,10,0,20,15,40,55,60,70,90}     "  << endl;
    cout << "     4. {50,30,30,20,0,5,30,45,50,60,80}      "  << endl;
    cout << "     5. {45,30,25,15,5,0,20,40,45,55,75}      "  << endl;
    cout << "     6. {75,55,50,40,30,20,0,15,20,30,50}     "  << endl;
    cout << "     7. {55,70,65,55,45,40,15,0,5,15,35}      "  << endl;
    cout << "     8. {50,75,70,60,50,45,20,5,0,40,30}      "  << endl;
    cout << "     9. {40,85,80,70,60,55,30,15,10,0,20}     "  << endl;
    cout << "     10.{20,120,100,90,80,75,50,35,30,20,0}   "  << endl;
    cout << "______________________________________________"  << endl;

    cout << "Enter your retail-to-retail route distance (km): ";
    cin>>totalRetailDistanceTravel;

    cout << "Total Retail-to-Retail Distance Traveled: ";
    cout<<totalRetailDistanceTravel<< " km" << endl;
    //Actual Route
    totalDistanceTravelledFromHQ=totalRetailDistanceTravel+totalDistanceTravelledFromHQ;
    cout << "Total Route Distance Traveled: ";
    cout <<totalDistanceTravelledFromHQ<< " km" << endl;
    cout<<"_______________________________________________________________"<<endl;
    return totalDistanceTravelledFromHQ;
}


void selectedGreedyRoute(RetailerSites& r, GreedyRoute& greedyRoute, OptimizedRoute& optimizedRoute) {

    greedyRoute.totalDistanceTravelledGreedy=calculateGreedyRoute(r);
    optimizedRoute.totalDistanceTravelled=calculateOptimizedRoute(r);
    cout<<"Optimized Route Distance:"<<optimizedRoute.totalDistanceTravelled<<"km"<<endl;

    char routeApproval;
    cout << "Do you wish to approve greedy route to be used by driver?[Y/N]" << endl;
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
