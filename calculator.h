#pragma once

#include <string>
#include "token_stream.h"

namespace calculator
{

double get_primary (parser::token_stream& ts);
double get_term (parser::token_stream& ts);
double get_expression (parser::token_stream& ts);
double calculate(const std::string& input_string);

}
