#ifndef CALCULATOR_CALC_H
#define CALCULATOR_CALC_H

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

class Calculator {

public:
    int result(string s);

    unsigned int depth(string s);

    bool correct(string s);

private:
    int i = 0, num;
    string str;

    enum List {
        number, add, sub, mul, div, bracket1, bracket2, binom, comma
    };
    List id;

    bool is_op(char ch);

    int choose(int n, int k);

    int combination();

    int priority2();

    int priority1();

    int rez();

    void getNext();

    char next();

    void deleteWhitespace();
};

#endif //CALCULATOR_CALC_H
