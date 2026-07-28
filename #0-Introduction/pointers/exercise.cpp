/* Try writing this:
Create:
int altitude = 100;

Create a pointer pointing to it.

Then:

Print altitude normally
Print its memory address
Use the pointer to change altitude to 250
Print altitude again

Expected output:

100
0x123abc
250 */

#include<iostream>

int main (){

int altitude = 100;

int* ptr = &altitude;

std::cout<<"Altitude "<< altitude << "\nmemory address"<< &altitude;

*ptr = 250;

std::cout<<"\nnew altitude "<<altitude;

}