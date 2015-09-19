#pragma once

#include "token.h"
#include <sstream>
#include <string>

namespace parser
{

class token_stream
{
public:
    token_stream(const std::string& s): full(false), buffer(), input(s){}

    void putback(token t);

    token get();
private:
    bool full;
    token buffer;
    std::istringstream input;

};

}


