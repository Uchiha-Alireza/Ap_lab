#pragma once
#include <stdexcept>
#include <string>
namespace Alireza{
class concatenate_error : public std::invalid_argument {
public:
    explicit concatenate_error(const std::string& message);
};
}