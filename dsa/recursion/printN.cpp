//Print numbers from 1 to N
//Given an integer N, print the numbers from 1 to N using recursion.
#include<iostream>



void printFunc(int n ,int count){
    if(count > n){
        return;
    }
    std::cout<< count;
    printFunc(n,++count);

}

int main (){

printFunc(10,1);

return 0;
}
