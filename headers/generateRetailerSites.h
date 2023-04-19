#ifndef GENERATERETAILERSITES_H_INCLUDED
#define GENERATERETAILERSITES_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

class RetailerSites{

public:
    std::string locations[10];
    double goodsWeight[10];
    int distancesFromSupplierHQ[10];
    int retailerConnectedToDistance[10];
    string retailerConnectedTo[10];

    RetailerSites(){
        locations[0] = "Retailer 1";
        locations[1] = "Retailer 2";
        locations[2] = "Retailer 3";
        locations[3] = "Retailer 4";
        locations[4] = "Retailer 5";
        locations[5] = "Retailer 6";
        locations[6] = "Retailer 7";
        locations[7] = "Retailer 8";
        locations[8] = "Retailer 9";
        locations[9] = "Retailer 10";

        distancesFromSupplierHQ[0] = 15;
        distancesFromSupplierHQ[1] = 20;
        distancesFromSupplierHQ[2] = 30;
        distancesFromSupplierHQ[3] = 50;
        distancesFromSupplierHQ[4] = 45;
        distancesFromSupplierHQ[5] = 70;
        distancesFromSupplierHQ[6] = 55;
        distancesFromSupplierHQ[7] = 50;
        distancesFromSupplierHQ[8] = 40;
        distancesFromSupplierHQ[9] = 20;

        // Retailers Connected To Retailer[] by skipping other retailer distance
        retailerConnectedTo[0] = "3";//15km;
        retailerConnectedTo[1] = "5";//25km;
        retailerConnectedTo[2] = "5";//15km;
        retailerConnectedTo[3] = "6";//30km;
        retailerConnectedTo[4] = "8";//45km;
        retailerConnectedTo[5] = "8";//20km;
        retailerConnectedTo[6] = "9";//15km;
        retailerConnectedTo[7] = "10";//30km;
        retailerConnectedTo[8] = "7";//15km;
        retailerConnectedTo[9] = "8";//30km;

        retailerConnectedToDistance[0] = 15;
        retailerConnectedToDistance[1] = 25;
        retailerConnectedToDistance[2] = 15;
        retailerConnectedToDistance[3] = 30;
        retailerConnectedToDistance[4] = 45;
        retailerConnectedToDistance[5] = 20;
        retailerConnectedToDistance[6] = 15;
        retailerConnectedToDistance[7] = 30;
        retailerConnectedToDistance[8] = 15;
        retailerConnectedToDistance[9] = 30;


        srand((unsigned) time(0));
        for (int locationCreated=0;locationCreated<10;locationCreated++){
            double goodsWeightCreated = (double) (rand() % 501);
            goodsWeight[locationCreated] = goodsWeightCreated ;
        }
    }

    void displayRetailerSitesInMainMenu(){
    std::cout << std::left << std::setw(20) << "Location" << std::setw(20) << "Weight (kg)"
    << std::setw(30) << "Distance from HQ (km)" << std::setw(30) <<  "Retailer Connected:"
    << "Distance (km):" <<std::endl;
    for (int i = 0; i < 10; i++) {
                std::cout << std::left << std::setw(23) << locations[i] << std::setw(25) << goodsWeight[i]
                << std::setw(30) << distancesFromSupplierHQ[i] << std::setw(27) << retailerConnectedTo[i]<< retailerConnectedToDistance[i]<< std::endl;
            }
    }

    void displayRetailerSitesUnoptimized() {
        std::cout << std::left << std::setw(20) << "Location" << std::setw(20) << "Weight (kg)"
        << std::setw(30) << "Distance from HQ (km)" << std::setw(30) <<  "Retailer Connected:"
        << "Distance (km):" <<std::endl;
        int locationsOnList=0;
        int locationToDelete1;
        int locationToDelete2;

            for (int i = 0; i < 10; i++) {
                if (goodsWeight[i]>=50){
                std::cout << std::left << std::setw(23) << locations[i] << std::setw(25) << goodsWeight[i] << std::setw(30) << distancesFromSupplierHQ[i] << std::setw(27) << retailerConnectedTo[i]<< retailerConnectedToDistance[i]<< std::endl;
                locationsOnList++;
                }
            }
            if (locationsOnList>9){
                cout<<"Over 8 Location! Select 2 retail numbers you wish to delete:";
                cin>>locationToDelete1;
                cin>>locationToDelete2;
                system("CLS");
                cout<<flush;
                std::cout << std::left << std::setw(20) << "Location" << std::setw(20) << "Weight (kg)" << std::setw(30) << "Distance from HQ (km)" << std::setw(30) <<  "Retailer Connected:"<< "Distance (km):" <<std::endl;
                for (int i = 0; i < 10; i++) {
                        if (i!=locationToDelete1-1 && i!=locationToDelete2-1)
                            if (goodsWeight[i]>=50)
                            std::cout << std::left << std::setw(23) << locations[i] << std::setw(25) << goodsWeight[i] << std::setw(30) << distancesFromSupplierHQ[i] << std::setw(27) << retailerConnectedTo[i]<< retailerConnectedToDistance[i]<< std::endl;

                }
            }

            else if (locationsOnList==9){
                cout<<"Over 8 Location! Select 1 retail number you wish to delete:";
                cin>>locationToDelete1;
                system("CLS");
                cout<<flush;
                std::cout << std::left << std::setw(20) << "Location" << std::setw(20) << "Weight (kg)" << std::setw(30) << "Distance from HQ (km)" << std::setw(30) <<  "Retailer Connected:"<< "Distance (km):" <<std::endl;
                for (int i = 0; i < 10; i++) {
                        if (i!=locationToDelete1-1)
                            if (goodsWeight[i]>=50)
                            std::cout << std::left << std::setw(23) << locations[i] << std::setw(25) << goodsWeight[i] << std::setw(30) << distancesFromSupplierHQ[i] << std::setw(27) << retailerConnectedTo[i]<< retailerConnectedToDistance[i]<< std::endl;
                }
            }
    }

    void saveToFile() {
        std::ofstream file("RL_InitialRoute.txt");
        if (file.is_open()) {
            file << "Retailer Locations, Goods Weight, and Distance from HQ List: " << std::endl;
            for (int i = 0; i < 10; i++) {
                file << "Location: " << locations[i] << ", Weight: " << goodsWeight[i] << "kg, Distance from HQ: "
                << distancesFromSupplierHQ[i] << "km, Retailer Connected: " << retailerConnectedTo[i]<<", Distance To Retailer:"
                << retailerConnectedToDistance[i]<<"km"<<std::endl;
            }
            file.close();
        } else {
            std::cout << "Error saving file" << std::endl;
        }
    }
};

#endif // GENERATERETAILERSITES_H_INCLUDED
