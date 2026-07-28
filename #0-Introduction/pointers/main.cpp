// pointers and memory allocation in C++
// pointer - storing memory address
// & operator - used to access the memory address of variable 
// derefrencing pointer - how to access the value stored at particular address -> using *with pointer 
#include<iostream>

int main (){

    int battery = 64;

    std::cout<<"battery " << battery;
    std::cout<<"\nmemory address "<< &battery;

    int* ptr = &battery;

    std::cout << "\n pointer variable "<< ptr;
    std::cout << "\n derefrencing pointer variable "<< *ptr;
}