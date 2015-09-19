#pragma once


namespace parser
{

class token
{
public:
    token(){};
    token(char ch): kind(ch), value() {}
    //token(double val): kind('V'), value(val) {}
    token(double val, char ch = 'V'): kind(ch), value(val) {}

    void clear();
    char get_kind();
    double get_value();
private:
    char kind;
    double value;
};

}

