#include "NewBranch.h"
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype>

int check_input(std::string input){
    std::string command;
    std::set<std::string> flags;
    std::string flag;
    std::istringstream iss(input);
    iss >> command;
    if (command == "register"){
        std::string username;
        std::string password;
        while (iss >> flag) {
            if (flag == "-u"){
                if (!(iss >> username)){
                    return -1;  
                }
                flags.insert(flag);
            } else if (flag == "-p"){
                if (!(iss >> password)){
                    return -1; 
                }
                flags.insert(flag);
            } else {
                return -1;  
            }
        }
        if (flags.size() < 2){
             return -1;  
        }
    }
    else if(command == "data"){
        std::string firstname;
        std::string lastname;
        std::string email;
        std::string phonenumber;
        while(iss>> flag){
            if (flag == "-fn") {
                if (!(iss >> firstname)){
                    return -1;
                }  
                flags.insert(flag);
            } 
            else if (flag == "-ln"){
                if (!(iss >> lastname)){
                    return -1;
                }  
                flags.insert(flag);
            }
            else if (flag == "-e"){
                if (!(iss >> email)){ 
                    return -1;
                }  
                flags.insert(flag);
            }
            else if (flag == "-ph"){
                if (!(iss >> phonenumber)){ 
                    return -1;
                }  
                flags.insert(flag);
            } 
            else{
                return -1;
            }
        }
        if (flags.size() < 4){
        return -1;  
        }
    }
    else if (command == "bio"){
        std::string description;
        std::getline(iss >> std::ws, description); 
        if (description.empty()){
            return -1;
        }  
    } 
    else{
        return -1;  
    }
    return 0; 
}
int check_username(const std::string& username){
    if(username.empty()){
        return -1;
    }
    if(!std::isalpha(username[0])){
        return -1;
    }
    char help=username[0];
    int exist_alpha=-1;
    for(int i=0;i<username.size();i++){
        char check = username[i];
        if(isalnum(check)==0 && check !='.'&& check !='_'){
            return -1;
        }
        if ((check == '.' || check == '_') && (help == '.' || help == '_')){
            return -1; 
        }
        help=check;
        if(i==username.size()-1&&(check=='.'||check=='_')){
            return -1;
        }
        if(isalpha(check)){
            exist_alpha=1;
        }
    }
    return exist_alpha;
}
int check_password(const std::string & password,const std::string & username){
    if(password.length()<6 || password.length()>20){
        return -1;
    }
    int exist_low=-1;
    int exist_upper=-1;
    int exist_digit=-1;
    int exist_special=-1;
    std::set<std::string> username_parts;
    std::string part;
    for(char tmp:username){
        if(isalnum(tmp)){
            part+=tmp;
        }
        else{
            if (!part.empty()){
                username_parts.insert(part);
                part.clear(); 
            }
        }
    }
     if (!part.empty()) {
        username_parts.insert(part);
    }
    char prev_char = '\0'; 
    int count = 1;         
    for (char c : password) {
        if (c >= 'a' && c <= 'z'){
            exist_low = 1;
        }
        if (c >= 'A' && c <= 'Z'){
            exist_upper = 1;
        }
        if (c >= '0' && c <= '9'){
            exist_digit = 1;
        }
        if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+' || c == '=') {
            exist_special = 1;
        }
        if (c == prev_char){
            count++;
            if (count > 3){
                return -1; 
            }
        }
        else{
            count = 1; 
        }
        prev_char = c; 
    }
    if (!exist_low || !exist_upper || !exist_digit || !exist_special){
        return -1;
    }
    for (const std::string& word : username_parts){
        if (password.find(word) != std::string::npos && word.length() > 3){
            return -1; 
        }
    }
    return 0; 
}
int check_name(const std::string& firstname, const std::string& lastname){
     for (char check : firstname){
        if (check < 'A' || (check > 'Z' && check < 'a') || check > 'z'){
            return -1; 
        }
    }
    int found=-1;
    if(lastname.empty()){
        return -1;
    }
    for (size_t i = 0; i < lastname.size(); ++i){
        char c = lastname[i];
        if ((c < 'A' || (c > 'Z' && c < 'a') || c > 'z') && c != '-'){
            return -1; 
        }
        if (c == '-') {
            if (found) {
                return -1; 
            }
            if (i == 0 || i == lastname.size() - 1 || !isalpha(lastname[i - 1]) || !isalpha(lastname[i + 1])) {
                return -1; 
            }
            found = 1;
        }
    }
    return 0;
}
int check_email(const std::string& email){
    size_t pos = email.find('@');
    size_t dc = email.rfind(".com");
    if (pos == std::string::npos || dc == std::string::npos || dc != email.size() - 4){
        return -1;
    }
    std::string username = email.substr(0, pos);
    std::string d = email.substr(pos + 1, dc - pos - 1);
    if (check_username(username) == -1){
        return -1; 
    }
    if (d.empty() || d[0] == '.' || d[d.size() - 1] == '.'){
        return -1; 
    }
    bool found_dot = false;
    for (size_t i = 0; i < d.size(); ++i){
        char c = d[i];
        if ((c < 'A' || (c > 'Z' && c < 'a') || c > 'z') && c != '.'){
            return -1; 
        }
        if (c == '.'){
            if (found_dot){
                return -1; 
            }
            found_dot = true;
        }
    }
    return 0; 
}
int check_phone(const std::string& p) {
    if (p.length() != 13 && p.length() != 11){
        return -1; 
    }
    if (p.length() == 13 && p.substr(0, 4) == "+989"){
        for (int i = 4; i < 13; ++i){
            if (p[i] < '0' || p[i] > '9'){
                return -1; 
            }
        }
        return 0; 
    }
    if (p.length() == 11 && p.substr(0, 2) == "09") {
        for (int i = 2; i < 11; ++i) {
            if (p[i] < '0' || p[i] > '9') {
                return -1; 
            }
        }
        return 0; 
    }
    return -1; 
}
int check_bio(const std::string& input){
    if (input.length() < 2 || input.front() != '"' || input.back() != '"'){
        return -1; 
    }
    std::string description = input.substr(1, input.length() - 2);

    if (description.empty()){
        return -1; 
    }
    return 0; 
}
std::string format_name(const std::string& name){
    std::string format = name;
    if (!format.empty()){
        format[0] = std::toupper(format[0]);
        std::transform(format.begin() + 1, format.end(), format.begin() + 1, ::tolower);
    }
    return format;
}
std::string format_lastname(const std::string& lastname){
    std::string format = lastname;
    bool capitalize_next = true;
    for (size_t i = 0; i < format.size(); ++i) {
        if (capitalize_next) {
            format[i] = std::toupper(format[i]);
            capitalize_next = false;
        } else {
            format[i] = std::tolower(format[i]);
        }
        if (format[i] == '-') {
            capitalize_next = true;
        }
    }
    return format;
}
std::string format_email(const std::string& email){
    std::string format = email;
    std::transform(format.begin(), format.end(), format.begin(), ::tolower);
    return format;
}
std::string format_phone(const std::string& phone){
    std::string format = phone;
    if (format.size() == 11 && format[0] == '0'){
        format = "+98-" + format.substr(1, 3) + "-" + format.substr(4, 3) + "-" + format.substr(7, 4);
    }
    return format;
}
std::string format_description(std::string description) {
    description.erase(0, description.find_first_not_of(" \n\r\t"));
    description.erase(description.find_last_not_of(" \n\r\t") + 1);
    size_t pos;
    while ((pos = description.find("\\n")) != std::string::npos) {
        description.replace(pos, 2, "\n");
    }
    std::string::iterator new_end = std::unique(description.begin(), description.end(), [](char lhs, char rhs) {
        return std::isspace(lhs) && std::isspace(rhs) && lhs == ' ';
    });
    description.erase(new_end, description.end());
    while ((pos = description.find("\n\n\n")) != std::string::npos) {
        description.replace(pos, 3, "\n\n");
    }
    std::stringstream input(description);
    std::string word, formatted_desc;
    std::string current_line;
    while (input >> word) {
        if (current_line.size() + word.size() + 1 > 40){
            formatted_desc += current_line + "\n";
            current_line = word;
        }
        else{
            if (!current_line.empty()){
                current_line += " ";
            }
            current_line += word;
        }
    }
    if (!current_line.empty()){
        formatted_desc += current_line + "\n";
    }
    return formatted_desc;
}
std::string format_bio(const std::string& bio) {
    std::string formatted_bio;
    std::string trimmed_bio = bio;
    trimmed_bio.erase(0, trimmed_bio.find_first_not_of(' '));
    trimmed_bio.erase(trimmed_bio.find_last_not_of(' ') + 1);
trimmed_bio.erase(
    std::unique(trimmed_bio.begin(), trimmed_bio.end(), [](char lhs, char rhs) {
        return std::isspace(lhs) && std::isspace(rhs);
    }),
    trimmed_bio.end()
);
    for (char c : trimmed_bio) {
        if (c == '\\') {
            formatted_bio += '\n';
        } else {
            formatted_bio += c;
        }
    }
    std::string result;
    std::istringstream iss(formatted_bio);
    std::string word;
    std::string line;
    while (iss >> word) {
        if (line.length() + word.length() + 1 <= 40) {
            line += (line.empty() ? "" : " ") + word;
        } else {
            result += line + "\n";
            line = word;
        }
    }
    if (!line.empty()) {
        result += line + "\n";
    }

    return result;
}