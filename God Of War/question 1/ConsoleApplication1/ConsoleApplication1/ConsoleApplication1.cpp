#include <iostream>
#include "Vector.cpp"
#include <stdexcept>

int main() {
    try {
        size_t size;
        std::cout << "Enter size of vector: ";
        std::cin >> size;
        if (std::cin.fail() || size <= 0) {
            throw std::invalid_argument("Invalid input for size.");
        }
        Vector<int> vec(size);
        std::cout << "Vector created with size: " << vec.Size() << " and capacity: " << vec.Capacity() << std::endl;
        vec.push_back(10);
        std::cout << "After push_back, size: " << vec.Size() << ", back: " << vec.back() << std::endl;
        vec.pop_back();
        std::cout << "After pop_back, size: " << vec.Size() << std::endl;
        vec.push_front(20);
        std::cout << "After push_front, front: " << vec.front() << ", size: " << vec.Size() << std::endl;
        try {
            std::cout << "Accessing index 10: " << vec.at(10) << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        std::cout << "Accessing element at index 0: " << vec[0] << std::endl;
        Vector<int> vec2(4, 7);
        vec += vec2;
        std::cout << "After concatenation, size: " << vec.Size() << std::endl;
        vec.clear();
        std::cout << "After clear, size: " << vec.Size() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }
    return 0;
}
