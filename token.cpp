#include "token.h"


namespace parser
{


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
