#include <iostream>
#include "Calculator.h"
#include "Printer.h"
using namespace std;

int ans;
unsigned int dp, h;

int main()
{
    string s;
    Calculator Calc;
    getline(cin, s);

    if (Calc.correct(s)) {
        dp = Calc.depth(s);
        ans = Calc.result(s);
        h = 7;
        for (int i = 1; i <= dp; i++)
            h = 2 * h + 1;

        Printer a(h);
        a.print_str(s);
        a.putChar('=');
        a.putInt(ans);
        //a.printConsole();
        a.printPicture();
        cout << ans;
    }
    else cout << "Incorrect input!";

    return 0;
}


/*
C(2 + 1, 2 + 1)

C(C(6, 4), 2)

C(3, C(2, 1))
*/
