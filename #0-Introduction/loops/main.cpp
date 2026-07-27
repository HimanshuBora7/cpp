// Write a program:

// A drone starts with:

// Battery = 100%

// Every loop:

// Reduce battery by 10%
// Print current battery
// If battery reaches 20%, print:
// "Warning: Return to home"

// Expected output:

// Battery: 100%
// Battery: 90%
// Battery: 80%
// Battery: 70%
// Battery: 60%
// Battery: 50%
// Battery: 40%
// Battery: 30%
// Battery: 20%
// Warning: Return to home

// Try using a while loop.


#include <iostream>

int main (){

    int battery = 100;

    while(battery >= 20){
        std::cout<< "Battery " << battery << "\n";
        battery -= 10;
        
    }
    if(battery < 20){
            std::cout<< "Warning: Return to home";
        }

    return 0;
}