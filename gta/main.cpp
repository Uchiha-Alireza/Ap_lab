#include "vault.h"
#include "SecureVault.h"
#include "Hacker.h"
int main(){
    Vault newVault;
    char * ptr=reinterpret_cast<char*>(&newVault);
    std::string* password = reinterpret_cast<std::string*>(ptr);
    bool* security = reinterpret_cast<bool*>(ptr+sizeof(std::string));
    int* money =reinterpret_cast<int*>(ptr+sizeof(std::string)+sizeof(bool));
    *password = "123";
    *security = false;
    *money = 0;
    newVault.checkWinCondition();
    std::cout<<"part 2:"<<std::endl;
    SecureVault mySecureVault;
    mySecureVault.checkHackerSuccess();
    std::cout<<"part 3:"<<std::endl;
    Hacker hacker;
    hacker.hack(mySecureVault); 
}