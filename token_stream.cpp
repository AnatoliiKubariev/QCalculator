#include "token_stream.h"

#include "token.h"
#include <sstream>
#include <stdexcept>

namespace parser
{

token_stream::token_stream(const std::string& s)
    : full(false)
    , buffer('N')
    , input(s){}

token token_stream::get()
{
    if(full == true)
    {
        token to_del = buffer;
        full = false;
        buffer.clear();
        return to_del;
    }

    char ch = 0;
    input >> ch;
    if(!input)
    {
        buffer.clear();
        return buffer;
    }


    switch(ch)
    {
    case '(': case ')': case '+': case '-': case '*': case '/':
        return token(ch);
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        input.putback(ch);
        double val;
        input >> val;
        return token(val);
    }
    default:
        throw std::logic_error("not value");
    }
}

void token_stream::putback(token t)
{
    if(full)
        throw std::logic_error("buffer si full");
    buffer = t;
    full = true;
}

}
