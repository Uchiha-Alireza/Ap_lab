#pragma once
#include <stdexcept>
#include <string>
class concatenate_error : public std::invalid_argument {
public:
    explicit concatenate_error(const std::string& message);
};