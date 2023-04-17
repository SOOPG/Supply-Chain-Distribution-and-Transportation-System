#ifndef SELECTEDOPTIMIZEDPATH_H_INCLUDED
#define SELECTEDOPTIMIZEDPATH_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "generateRetailerSites.h"
using namespace std;

void displayOptimizeRoute(RetailerSites retailerBeforeFilterRoute){

        RetailerSites retailerList=retailerBeforeFilterRoute;

        std::cout << std::left << std::setw(20)
        << "Location" << std::setw(20)
        << "Weight (kg)" << std::setw(30)
        << "Distance from HQ (km)" << std::setw(30)
        <<  "Retailer Connected:"
        << "Distance (km):" <<std::endl;
        for (int i = 0; i < 10; i++) {
                if(retailerBeforeFilterRoute.goodsWeight[i]>=100 && retailerBeforeFilterRoute.distancesFromSupplierHQ[i]<=30){
                    std::cout << std::left << std::setw(23)
                    << retailerBeforeFilterRoute.locations[i] << std::setw(25) << retailerBeforeFilterRoute.goodsWeight[i] << std::setw(30)
                    << retailerBeforeFilterRoute.distancesFromSupplierHQ[i] << std::setw(27) << retailerBeforeFilterRoute.retailerConnectedTo[i]
                    << retailerBeforeFilterRoute.retailerConnectedToDistance[i]<< std::endl;
                }
            }
    }

void selectedOptimizedRoute(RetailerSites r){


    OptimizedRoute routeAvailable = r;
    char routeApproval;
    system("CLS");
    cout<<flush;

    routeAvailable.displayRouteDistance(retailerAvailable);

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


class OptimizedRoute{

    public:
        std::string locations[10];
        double goodsWeight[10];
        int distancesFromSupplierHQ[10];
        int retailerConnectedToDistance[10];
        string retailerConnectedTo[10];



    OptimizedRoute(){

    }

    void displayRouteDistance(){

        }

};

#endif // SELECTEDOPTIMIZEDPATH_H_INCLUDED
