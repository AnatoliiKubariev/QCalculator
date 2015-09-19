#pragma once


namespace parser
{

class token
{
public:
    token(char ch);
    token(double val, char ch = 'V');

    char get_kind();
    double get_value();
    void clear();

private:
    char kind;
    double value;
};

}

