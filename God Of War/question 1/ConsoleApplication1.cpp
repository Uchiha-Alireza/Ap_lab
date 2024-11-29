#include <iostream>
#include "Vector.h"
#include "Weapon.h"
#include "Blade.h"
#include "Bow.h"
#include "Mace.h"

int main() {
    Alireza::vector<Weapon*> weapons;

    Blade* blade = new Blade(100, 10.0f, 2, 1.5f, true, false);
    Bow* bow = new Bow(80, 8.0f, 1, 2.0f);
    Mace* mace = new Mace(150, 15.0f, 3, 5);

    weapons.push_back(blade);
    weapons.push_back(bow);
    weapons.push_back(mace);

    for (auto& it : weapons) {
        std::cout << "Weapon ID: " << it->getId() << ", Power: " << it->getPower() << ", Durability: " << it->getDurability() << std::endl;
    }

    delete blade;
    delete bow;
    delete mace;

    return 0;
}
