#include "Exception.h"
	concatenate_error::concatenate_error(const std::string& message) : std::invalid_argument(message) {}
