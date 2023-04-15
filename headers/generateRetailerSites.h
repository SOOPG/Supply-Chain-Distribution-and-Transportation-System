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

private:
    std::string locations[10];
    double goodsWeight[10];
    double distancesFromHQ[10];

public:
    RetailerSites(){
        locations[0] = "Retailer A";
        locations[1] = "Retailer B";
        locations[2] = "Retailer C";
        locations[3] = "Retailer D";
        locations[4] = "Retailer E";
        locations[5] = "Retailer F";
        locations[6] = "Retailer G";
        locations[7] = "Retailer H";
        locations[8] = "Retailer I";
        locations[9] = "Retailer J";

        distancesFromHQ[0] = 15;
        distancesFromHQ[1] = 20;
        distancesFromHQ[2] = 30;
        distancesFromHQ[3] = 50;
        distancesFromHQ[4] = 45;
        distancesFromHQ[5] = 70;
        distancesFromHQ[6] = 55;
        distancesFromHQ[7] = 50;
        distancesFromHQ[8] = 40;
        distancesFromHQ[9] = 20;

        srand((unsigned) time(0));
        for (int locationCreated=0;locationCreated<10;locationCreated++){
            double goodsWeightCreated = (double) (rand() % 501);
            goodsWeight[locationCreated] = goodsWeightCreated ;
        }
    }

    void displayRetailerSites() {
    std::cout << std::left << std::setw(20) << "Location" << std::setw(20) << "Weight (kg)" << std::setw(20) << "Distance from HQ (km)" << std::endl;
    for (int i = 0; i < 10; i++) {
            std::cout << std::left << std::setw(20) << locations[i] << std::setw(20) << goodsWeight[i] << std::setw(20) << distancesFromHQ[i] << std::endl;
        }
    }

    void saveToFile() {
        std::ofstream file("RL_InitialRoute.txt");
        if (file.is_open()) {
            file << "Retailer Locations, Goods Weight, and Distance from HQ List: " << std::endl;
            for (int i = 0; i < 10; i++) {
                file << "Location: " << locations[i] << ", Weight: " << goodsWeight[i] << "kg, Distance from HQ: " << distancesFromHQ[i] << "km" << std::endl;
            }
            file.close();
        } else {
            std::cout << "Error saving file" << std::endl;
        }
    }
};

#endif // GENERATERETAILERSITES_H_INCLUDED
