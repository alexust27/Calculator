#include "Calculator.h"

int Calculator::result(string s) {
    str = std::move(s);
    return combination();
}

unsigned int Calculator::depth(string s) {
    unsigned int dpmax = 0, dp = 0, b1, b2;
    b1 = b2 = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'c' || s[i] == 'C') {
            dp++;
            i++;
            while (s[i] == ' ') {
                i++;
            }
            continue;
        }
        if (s[i] == '(')
            b1++;
        if (s[i] == ')') {
            if (b1 - b2 == 0) {
                dpmax = max(dpmax, dp);
                dp--;
            } else b2++;
        }

    }
    return dpmax;
}

bool Calculator::correct(string s) {
    int op = 0, cl = 0, b = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ')')
            cl++;
        if (s[i] == '(')
            op++;
        if (s[i] == 'c' || s[i] == 'C') continue;
        if (s[i] == '-' && i != 0)
            if (b == 0 && s[i - 1] != '(')
                return false;
            else if (s[i - 1] == '(') continue;
        if (is_op(s[i]) && i != 0 && b == 0) return false;
        if (s[i] == '(' && b == 1) return false;
        if (s[i] == ')' && b == 0) return false;
        if (!isdigit(s[i]) && !is_op(s[i]) && s[i] != '(' && s[i] != ')' && s[i] != ' ') return false;
        if (cl > op) return false;
        if (is_op(s[i]) || s[i] == '(') b = 0;
        if (isdigit(s[i]) || s[i] == ')') b = 1;
    }
    if (b == 0) return false;
    return cl == op;
}

bool Calculator::is_op(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',';
}

int Calculator::choose(int n, int k) {
    unsigned long long denominator = 1, numerator = 1;
    for (int i = n; i > k; --i)
        numerator *= i;
    for (int i = 1; i <= (n - k); ++i)
        denominator *= i;
    return static_cast<int>(numerator / denominator);
}

int Calculator::combination() {
    int left = priority2();
    while (true) {
        if (id == comma) {
            int right = priority2();
            if (right <= left)
                left = choose(left, right);
            else {
                cout << "Incorrect C, k > n" << endl;
                exit(0);
            }
        } else {
            return left;
        }
    }
}

int Calculator::priority2() {
    int left = priority1();
    while (true) {
        switch (id) {
            case sub:
                left = left - priority1();
                break;
            case add:
                left = left + priority1();
                break;
            default:
                return left;
        }
    }
}

int Calculator::priority1() {
    int left = rez();
    while (true) {
        switch (id) {
            case mul:
                left = left * rez();
                break;
            case div: {
                int r = rez();
                if (r != 0)
                    left = left / r;
                else {
                    cout << "division by zero";
                    exit(0);
                }
                break;
            }
            default:
                return left;
        }
    }
}

int Calculator::rez() {
    getNext();
    int res;
    switch (id) {
        case number:
            res = num;
            getNext();
            break;
        case sub:
            res = -rez();
            break;

        case bracket1:
            res = combination();
            if (id != bracket2) {
                cout << ") missing";
                exit(0);
            }
            getNext();
            break;
        case binom:
            res = combination();
            getNext();
            break;

        default:
            cout << "Incorrect!";
            exit(0);
    }
    return res;
}

void Calculator::getNext() {
    deleteWhitespace();
    char ch = next();
    num = 0;
    if (isdigit(ch)) {
        while (isdigit(ch)) {
            num = num * 10 + ch - '0';
            ch = next();
        }
        i--;
        id = number;
    } else {
        switch (ch) {
            case '+':
                id = add;
                break;
            case '-':
                id = sub;
                break;
            case '*':
                id = mul;
                break;
            case '/':
                id = div;
                break;
            case '(':
                id = bracket1;
                break;
            case ')':
                id = bracket2;
                break;
            case ',':
                id = comma;
                break;
            default:
                if (ch == 'C' || ch == 'c')
                    id = binom;
                break;
        }
    }
    deleteWhitespace();
}

char Calculator::next() {
    if (i < str.length()) {
        char c = str[i];
        i++;
        return c;
    } else {
        return '\0';
    }
}

void Calculator::deleteWhitespace() {
    while (next() == ' ') {
    }
    i--;
}
