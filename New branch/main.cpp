#include "NewBranch.h"
#include <iostream>
#include <string>
#include <sstream>
int main() {
    std::string input, username, password, firstname, lastname, email, phonenumber, bio_description;
    while (true) {
        std::getline(std::cin, input);
        if (check_input(input) == -1) {
            std::cout << "invalid command\n";
            continue;
        }
        std::istringstream iss(input);
        std::string command, flag_u, flag_p;
        iss >> command >> flag_u >> username >> flag_p >> password;

        if (command == "register" && flag_u == "-u" && flag_p == "-p") {
            if (check_username(username) == -1) {
                std::cout << "invalid username format\n";
                continue;
            }
            if (check_password(password, username) == -1) {
                std::cout << "weak password\n";
                continue;
            }
            std::cout << "register successful\n";
            break;
        } else {
            std::cout << "invalid command\n";
        }
    }
    while (true) {
        std::getline(std::cin, input);
        if (check_input(input) == -1) {
            std::cout << "invalid command\n";
            continue;
        }
        std::istringstream iss(input);
        std::string command, flag_fn, flag_ln, flag_e, flag_ph;
        iss >> command >> flag_fn >> firstname >> flag_ln >> lastname >> flag_e >> email >> flag_ph >> phonenumber;

        if (command == "data" && flag_fn == "-fn" && flag_ln == "-ln" && flag_e == "-e" && flag_ph == "-ph") {
            if (check_name(firstname, lastname) == -1) {
                std::cout << "wrong name format\n";
                continue;
            }
            if (check_email(email) == -1) {
                std::cout << "invalid email format\n";
                continue;
            }
            if (check_phone(phonenumber) == -1) {
                std::cout << "invalid phone number\n";
                continue;
            }
            std::cout << "data saved successfully\n";
            break;
        } else {
            std::cout << "invalid command\n";
        }
    }
    while (true) {
        std::getline(std::cin, input);
        if (check_input(input) == -1) {
            std::cout << "invalid command\n";
            continue;
        }
        std::istringstream iss(input);
        std::string command;
        iss >> command;
        std::getline(iss, bio_description);  
        if (command == "bio") {
            bio_description = bio_description.substr(1);  
            if (check_bio(bio_description) == -1) {
                std::cout << "invalid biography format\n";
                continue;
            }
            break;
        } else {
            std::cout << "invalid command\n";
        }
    }
    std::cout << "----------\n";
    std::cout << format_name(firstname) << " " << format_name(lastname) << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Phone Number: " << format_phone(phonenumber) << "\n\n";
    std::cout << "Biography:\n" << format_bio(bio_description);
    std::cout << "----------\n";
    return 0;
}
