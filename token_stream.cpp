#include "token_stream.h"

#include "token.h"
#include <sstream>
#include <stdexcept>

namespace parser
{

token token_stream::get()
{
    auto s = input.str();
    auto pos = input.tellg();

    if(!input)
    {
        buffer.clear();
        return buffer;
    }

    if(full == true)
    {
        full = false;
        return buffer;
    }

    char ch;
    input >> ch;

    switch(ch)
    {
    case '(': case ')': case '+': case '-': case '*': case '/':
        return token(ch);
    case ',':
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
