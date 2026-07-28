// Create these functions:

// void readSensor()

// prints:
// Reading sensors...

// void checkBattery(int battery)

// if battery < 20:
// Low battery

// otherwise:

// Battery OK
// int calculateDistance(int speed, int time)
// returns distance

// Then call them from main().

// Expected output:

// Reading sensors...
// Battery OK
// Distance: 300 meters

#include <iostream>
void readSensor(){
    std::cout << "Reading sensors...\n";

}

void checkBattery(int battery){
    if(battery < 20){
        std::cout<<"Low battery\n";
    }
    else{
        std::cout<<"Battery OK\n";
    }
}

int calculateDistance(int speed,int time){

    int distance = speed * time;

    return distance;
}

int main (){
    readSensor();
    checkBattery(30);

    int speed = 20;
    int time = 15;
    int distance = calculateDistance(speed,time);
    std::cout<<"Distance: " << distance << "m";

    return 0;
}

