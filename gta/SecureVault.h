#ifndef SECUREVAULT_H
#define SECUREVAULT_H
#include "Vault.h"
class SecureVault : public Vault {
public:
    SecureVault();
    void checkHackerSuccess() const;
    void setMoney(int) = delete;
    void setPassword(const std::string& newPassword) = delete;
    void disableSecurity() = delete;
    friend class Hacker;
};
#endif 
