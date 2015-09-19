#include "token.h"


namespace parser
{

token::token(char ch)
    : kind(ch)
    , value(0) {}

token::token(double val, char ch /*= 'V'*/)
    : kind(ch)
    , value(val) {}


void token::clear()
{
    kind = 'N';
    value = 0;
}

char token::get_kind()
{
    return kind;
}

double token::get_value()
{
    return value;
}

}
