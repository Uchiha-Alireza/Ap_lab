#include "Hacker.h"
#include <iostream>

void Hacker::hack(SecureVault& vault) {
    vault.password = "123"; 
    vault.security = false;  
    vault.money = 0;       
    std::cout << "Hacking successful!" << std::endl;
    vault.checkHackerSuccess(); 
}
