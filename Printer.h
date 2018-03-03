#ifndef CALCULATOR_PRINTER_H
#define CALCULATOR_PRINTER_H

#include <iostream>
#include <vector>
#include <string>

const unsigned int N = 5; //width
//const int M = 5; //height
const char c = 'X';

using namespace std;

class Printer {
private:
    size_t size;
    size_t M;

    vector<vector<string>> num;
    vector<string> ans;
    vector<string> minus;
    vector<string> plus;
    vector<string> bracket1;
    vector<string> bracket2;
    vector<string> equal;
    vector<string> mul;
    vector<string> div;
    vector<string> binom;
    FILE *pic;

    void changeSize(size_t x);

    void putAns(vector<string> a, int x1, int x2, size_t y);

public:
    explicit Printer(size_t h);

    ~Printer();

    void putChar(char ch);

    int size_ans();

    void putInt(int v);

    void printConsole();

    void printPicture();

    void print_str(string s);
};

#endif //CALCULATOR_PRINTER_H
