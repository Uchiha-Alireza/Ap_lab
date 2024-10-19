#ifndef VAULT_H
#define VAULT_H
#include <iostream>
class Vault{
protected:
    std::string password;
    bool security;
    int money;
public:
    Vault();
    int getMoney();
    void setMoney(int);
    void checkWinCondition();
};
#endif
