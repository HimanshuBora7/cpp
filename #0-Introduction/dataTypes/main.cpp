// Introduction to the data types 

#include <iostream>
#include <string>
int main (){

    std::string droneName = "Raptor";
    int batteryPercentage = 85;
    float altitude = 120.5;
    bool GPSstatus = true;
    float speed = 25.4;

    std::cout << "Drone: " << droneName << "\nBattery: "<< batteryPercentage << "%" << "\nAltitude: " << altitude << "m" <<"\nGPS Locked: " << GPSstatus << "\nSpeed: " << speed << "m/s";

    return 0;

}