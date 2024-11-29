#include <iostream>
#include "WeappnManager.h"

void WeaponManager::addWeapon(Weapon* weapon) {
    weapons.push_back(weapon);
}
std::string WeaponManager::getWeaponType(int index) {
    if (Blade* blade = dynamic_cast<Blade*>(weapons.at(index))) {
        return "Blade";
    }
    else if (Bow* bow = dynamic_cast<Bow*>(weapons.at(index))) {
        return "Bow";
    }
    else if (Mace* mace = dynamic_cast<Mace*>(weapons.at(index))) {
        return "Mace";
    }
    return "Unknown";
}
int WeaponManager::getWeaponPower(int index) {
    return weapons.at(index)->getPower();
}
float WeaponManager::getWeaponDurability(int index) {
    return weapons.at(index)->getDurability();
}
int WeaponManager::getWeaponId(int index) {
    return weapons.at(index)->getId();
}
int WeaponManager::getTotalPower() {
    int totalPower = 0;
    for (size_t i = 0; i < weapons.Size(); ++i) {
        totalPower += weapons.at(i)->getPower();
    }
    return totalPower;
}
void WeaponManager::displayWeapons() {
    for (size_t i = 0; i < weapons.Size(); ++i) {
        std::cout << "Weapon Type: " << getWeaponType(i) << ", Power: " << getWeaponPower(i) << ", Durability: " << getWeaponDurability(i) << std::endl;
    }
}
void WeaponManager::sortWeaponsByPower() {
    for (size_t i = 0; i < weapons.Size(); ++i) {
        for (size_t j = i + 1; j < weapons.Size(); ++j) {
            if (weapons.at(i)->getPower() < weapons.at(j)->getPower()) {
                std::swap(weapons[i], weapons[j]);
            }
        }
    }
}