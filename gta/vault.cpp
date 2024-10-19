#include "vault.h"
#include <iostream>
Vault::Vault(){
    password = "hNcaal9*930okf";
    security = true;
    money = 100;
}
int Vault::getMoney(){
        std::cout << "You lose!" << std::endl;
        return money;
}
void Vault::setMoney(int newValue){
        std::cout << "You lose!" << std::endl;
        money = newValue;
}
void Vault::checkWinCondition(){
    if (money == 0 && password=="123" && security==false){
        std::cout << "You win!" << std::endl;
    }
    else{
        std::cout << "You have been arrested!" << std::endl;
    }
}