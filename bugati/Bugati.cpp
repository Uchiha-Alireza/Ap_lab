#include "Car.h"
#include "Motorcycle.h"
#include "Bike.h"
#include "Node.h"
#include "Vehicle.h"
int main() {
    LinkedList store;

    store.addVehicle(new Car("Toyota", "Corolla", "White", 1, 2020, 180, 20000));
    store.addVehicle(new Motorcycle("Yamaha", "YZF-R3", "Blue", 2, 2021, 200, 5000, 50));
    store.addVehicle(new Bike("Giant", "Escape 3", "Black", 3, 2019, 30));

    std::cout << "Available Vehicles:\n";
    store.displayVehicles();

    std::cout << "\nSelling Vehicle with ID 1:\n";
    store.sellVehicle(1);
    std::cout << "\nTrying to sell Vehicle with ID 1 again:\n";
    store.sellVehicle(1);

    return 0;
}
