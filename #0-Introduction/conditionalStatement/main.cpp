// Write a program:

// A drone has:

// Battery = 75%
// Speed = 15 m/s
// Flight time = 20 seconds
// GPS = true

// Calculate:

// Distance traveled
// Check if takeoff is allowed:
// Battery > 30%
// GPS locked

// Expected output:

// Distance: 300 meters
// Takeoff allowed: true

#include <iostream>

int main (){

    int battery = 75;
    float speed = 15.2;
    float flightTime = 20.1;
    bool gpsLocked = true;

    float distance = speed * flightTime;

    bool takeoff = false;

    if(battery > 30 && gpsLocked){
        takeoff = true;
    }
    std::cout << "Distance: " << distance;
    std::cout << "\nTakeoff allowed: " <<std::boolalpha << takeoff;

    return 0;

}