#include "token.h"
#include "token_stream.h"
#include "calculator.h"

#include <istream>
#include <stdexcept>

namespace calculator
{
//numbers and parentheses
double get_primary (parser::token_stream& ts)
{
    parser::token t = ts.get();
    switch(t.get_kind())
    {
    case '(':
    {
        double res = get_expression(ts);
        t = ts.get();
        if(t.get_kind() != ')')
            throw std::logic_error("no ')' after '('");
        return res;
    }
    case 'V':
        return t.get_value();
    case '-':
        return -get_primary(ts);
    default:
        throw std::logic_error("no value");
    }
}

// * and /
double get_term (parser::token_stream& ts)
{
    double res = get_primary(ts);
    parser::token t = ts.get();

    while(true)
    {
        switch (t.get_kind())
        {
        case '*':
            res *= get_primary(ts);
            t = ts.get();
            break;
        case '/':
        {
            double div = get_primary(ts);
            if (div == 0)
                throw std::logic_error("division by zero");
            res /= div;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return res;
        }
    }

}

// + and -
double get_expression (parser::token_stream& ts)
{
    double res = get_term(ts);
    parser::token t = ts.get();;

    while(true)
    {
        switch (t.get_kind())
        {
        case '+':
            res += get_term(ts);
            t = ts.get();
            break;
        case '-':
            res -= get_term(ts);
            t = ts.get();
            break;
        case 'N':
            return res;
        default:
            ts.putback(t);
            return res;
        }
    }

}

}
