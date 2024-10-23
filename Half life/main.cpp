#include "Gun.h"
#include <iostream>

int main(){
    Gun gun1,gun2,gun3,gun4,gun5;
    std::cout << "Enter details for Gun 1:" << std::endl;
    std::cin >> gun1;  
    std::cout << "Enter details for Gun 2:" << std::endl;
    std::cin >> gun2;  
    std::cout << gun1;
    std::cout << gun2;
    gun3=gun2+gun1;
    std::cout<<gun3;
    if(gun1==gun2){
        std::cout<<"is equal";
    }
    if(gun2!=gun1){
        std::cout<<"is not equal ";
    }
    gun3+=gun2;
    std::cout<<gun3;
    gun4=gun1+gun3;
    std::cout<<gun4;
    gun5=gun4++;
    std::cout<<gun5;
    std::cout<<gun4;
    gun5=gun3--;
    std::cout<<gun5;
    std::cout<<gun3;
    gun5=--gun2;
    std::cout<<gun5;
    std::cout<<gun2;
    gun5=++gun1;
    std::cout<<gun5;
    std::cout<<gun1;
    gun5[120];
    std::cout<<gun5;
    gun2*3;
    std::cout<<gun2;
    gun3/4;
    std::cout<<gun3;
    gun1*=2;
    std::cout<<gun1;
    gun4/=5;
    std::cout<<gun4;
    return 0;
}