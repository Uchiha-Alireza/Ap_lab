#include "SecureVault.h"
#include <iostream>

SecureVault::SecureVault(){}
void SecureVault::checkHackerSuccess() const{
    std::cout << "Attempt to hack has been detected!" << std::endl;
}
