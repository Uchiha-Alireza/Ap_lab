#include <iostream>
#include "CDLinkedList.h"

void menu(LinkedList& list) {
    int choice;
    do {
        std::cout << "\n--- Gun List Menu ---\n";
        std::cout << "1. Add Gun\n";
        std::cout << "2. Remove Gun\n";
        std::cout << "3. Restore Gun\n";
        std::cout << "4. Print List\n";
        std::cout << "5. Compare Guns\n";
        std::cout << "6. Double Ammo of a Gun\n";
        std::cout << "7. Halve Ammo of a Gun\n";
        std::cout << "8. Find Gun by Name\n"; 
        std::cout << "9. Exit\n";
        std::cout << "10. DeActive Gun\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int position;
        std::string nameGun;
        std::string gunName;
        int automatic;
        bool s;
        float FireRate;
        int ammo;

        switch (choice) {
        case 1: {
            std::cout << "Enter gun name: ";
            std::cin >> gunName;
            std::cout << "Enter ammo: ";
            std::cin >> ammo;
            std::cout << "Gun is automatic? (0: yes, 1: no): ";
            std::cin >> automatic;
            s = (automatic == 0);
            std::cout << "Enter fire rate: ";
            std::cin >> FireRate;
            Gun newGun(ammo, gunName, FireRate, s, true);
            list.addGun(newGun);
            std::cout << "Gun added.\n";
            break;
        }
        case 2: {
            std::cout << "Enter name gun to remove: ";
            std::cin >> nameGun;
            list.removeGun(nameGun);
            std::cout << "Gun removed.\n";
            break;
        }
        case 3: {
            std::cout << "Enter name gun to restore: ";
            std::cin >> gunName;
            list.ActiveGun(gunName);
            std::cout << "Gun restored.\n";
            break;
        }
        case 4: {
            list.displayGuns();
            break;
        }
        case 5: {
            std::string nameGun1, nameGun2;
            std::cout << "Enter name of first gun: ";
            std::cin >> nameGun1;
            std::cout << "Enter name of second gun: ";
            std::cin >> nameGun2;

            Node* gun1 = list.findGunByName(nameGun1);
            Node* gun2 = list.findGunByName(nameGun2);

            if (gun1 && gun2) {
                if (list.IsGreaterThan(gun1, gun2)) {
                    std::cout << "Gun \"" << nameGun1 << "\" is greater than gun \"" << nameGun2 << "\".\n";
                }
                else if (list.IsLessThan(gun1, gun2)) {
                    std::cout << "Gun \"" << nameGun1 << "\" is less than gun \"" << nameGun2 << "\".\n";
                }
                else {
                    std::cout << "Both guns \"" << nameGun1 << "\" and \"" << nameGun2 << "\" are equal.\n";
                }
            }
            else {
                if (!gun1) {
                    std::cout << "Gun \"" << nameGun1 << "\" not found.\n";
                }
                if (!gun2) {
                    std::cout << "Gun \"" << nameGun2 << "\" not found.\n";
                }
            }
            break;
        }
        case 6: {
            std::string gunName;
            std::cout << "Enter name of gun to double ammo: ";
            std::cin >> gunName;
            Node* gunNode = list.findGunByName(gunName);
            if (gunNode) {
                list.DoubleAmmo(gunNode);
                std::cout << "Ammo of gun \"" << gunName << "\" doubled.\n";
            }
            else {
                std::cout << "Gun \"" << gunName << "\" not found.\n";
            }
            break;
        }
        case 7: {
            std::string gunName;
            std::cout << "Enter name of gun to halve ammo: ";
            std::cin >> gunName;
            Node* gunNode = list.findGunByName(gunName);

            if (gunNode) {
                list.HalveAmmo(gunNode);
                std::cout << "Ammo of gun \"" << gunName << "\" halved.\n";
            }
            else {
                std::cout << "Gun \"" << gunName << "\" not found.\n";
            }
            break;
        }
        case 8: {
            std::cout << "Enter name of gun to find: ";
            std::cin >> gunName;
            Node* foundGun = list.findGunByName(gunName);
            if (foundGun) {
                std::cout << "Gun found: " << foundGun->getData().GetName() << ", Ammo: " << foundGun->getData().GetAmmo() << "\n";
            }
            else {
                std::cout << "Gun not found.\n";
            }
            break;
        }
        case 9: {
            std::cout << "Exiting...\n";
            break;
        }
        case 10: {
            std::cout << "Enter name gun to DeActived: ";
            std::cin >> gunName;
            list.DeActiveGun(gunName);
            std::cout << "Gun DeActived.\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 9);
}
int main() {
    LinkedList list;
    menu(list);
    return 0;
}
