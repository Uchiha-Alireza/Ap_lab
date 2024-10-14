#ifndef NEWBRANCH_H
#define NEWBRANCH_H
#include <string>
int check_input(std::string);
int check_username(const std::string &);
int check_password(const std::string & ,const std::string &);
int check_email(const std::string&);
int check_phone(const std::string&);
int check_bio(const std::string&);
int check_name(const std::string &,const std::string &);
std::string format_name(const std::string&);
std::string format_lastname(const std::string&);
std::string format_email(const std::string&);
std::string format_phone(const std::string&);
std::string format_description(std::string);
std::string format_bio(const std::string&);
#endif