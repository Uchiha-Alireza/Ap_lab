#include <iostream>
#include "WeappnManager.h"
int main() {
    WeaponManager manager;
    Blade* blade = new Blade(100, 10.0f, 2, 1.5f, true, false);
    Bow* bow = new Bow(80, 8.0f, 1, 2.0f);
    Mace* mace = new Mace(150, 15.0f, 3, 5);

    manager.addWeapon(blade);
    manager.addWeapon(bow);
    manager.addWeapon(mace);

    std::cout << "All Weapons:" << std::endl;
    manager.displayWeapons();

    std::cout << "\nTotal Power: " << manager.getTotalPower() << std::endl;

    std::cout << "\nSorted Weapons by Power:" << std::endl;
    manager.sortWeaponsByPower();
    manager.displayWeapons();
    delete blade;
    delete bow;
    delete mace;

    return 0;
}
