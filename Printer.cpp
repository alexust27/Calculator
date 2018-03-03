#include "Printer.h"

Printer::Printer(size_t h) {

    pic = fopen("output.bmp", "wb");
    M = h;
    size = 1;
    num.resize(10);
    for (int i = 0; i < 10; ++i) {
        num[i].resize(M);
        for (int j = 0; j < M; ++j)
            num[i][j].resize(N, ' ');
    }
    ans.resize(M);
    plus.resize(M);
    minus.resize(M);
    bracket1.resize(M);
    bracket2.resize(M);
    minus.resize(M);
    equal.resize(M);
    mul.resize(M);
    div.resize(M);
    binom.resize(M);
    for (int j = 0; j < M; ++j) {
        ans[j].resize(N + 1, ' ');
        plus[j].resize(N, ' ');
        minus[j].resize(N, ' ');
        bracket1[j].resize(N, ' ');
        bracket2[j].resize(N, ' ');
        minus[j].resize(N, ' ');
        equal[j].resize(N, ' ');
        mul[j].resize(N, ' ');
        div[j].resize(N, ' ');
        binom[j].resize(N, ' ');
    }

    int i, j;
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            //C
            if (i == 0 || i == M - 1 || (j == 0 && i != 0 && i != M - 1)) binom[i][j] = c;
            //equal
            if (i == M / 3 || i == 2 * M / 3) equal[i][j] = c;

            //div
            if (i < M / 2 && j == N - 1 || j == N / 2 && i == M / 2 || i > M / 2 && j == 0)
                div[i][j] = c;

            //minus
            if (i == M / 2)
                minus[i][j] = c;

            // make_plus()
            if (i == M / 2 || j == N / 2 && i < M / 2 + 3 && i > M / 2 - 3)
                plus[i][j] = c;

            //make_numbers()
            if (i != 0 && i != M - 1 && j == 0) bracket1[i][j] = c;
            bracket1[0][1] = bracket1[M - 1][1] = c;

            if (i != 0 && i != M - 1 && j == N - 1) bracket2[i][j] = c;
            bracket2[0][N - 2] = bracket2[M - 1][N - 2] = c;
        }

    mul[M / 2][N / 2] = mul[M / 2 - 1][N / 2 - 1] = mul[M / 2 - 1][N / 2 + 1] =
    mul[M / 2 + 1][N / 2 - 1] = mul[M / 2 + 1][N / 2 + 1] = c;

    //0
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (i == 0)num[0][i][j] = c;
            if (i == M - 1) num[0][i][j] = c;
            else num[0][i][0] = num[0][i][N - 1] = c;
        }
    //1
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (j == N - 1) num[1][i][j] = c;
            if (i < M / 2 && j >= N / 2 && N - i - 1 == j) num[1][i][j] = c;
        }
    //2
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (i == 0) num[2][i][j] = c;
            if (i == M / 2) num[2][i][j] = c;
            if (i == M - 1) num[2][i][j] = c;
            else if (i > M / 2) num[2][i][0] = c;
            else num[2][i][N - 1] = c;
        }
    //3
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (i == 0) num[3][i][j] = c;
            if (i == M / 2) num[3][i][j] = c;
            if (i == M - 1) num[3][i][j] = c;
            else num[3][i][N - 1] = c;
        }
    //4
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (i == M / 2) num[4][i][j] = c;
            if (i < M / 2) num[4][i][0] = num[4][i][N - 1] = c;
            else num[4][i][N - 1] = c;
        }
    //5
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (i == 0) num[5][i][j] = c;
            if (i == M / 2) num[5][i][j] = c;
            if (i == M - 1) num[5][i][j] = c;
            else if (i < M / 2) num[5][i][0] = c;
            else num[5][i][N - 1] = c;
        }
    //6
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (i == 0) num[6][i][j] = c;
            if (i == M / 2) num[6][i][j] = c;
            if (i == M - 1) num[6][i][j] = c;
            if (i < M / 2) num[6][i][0] = c;
            else num[6][i][0] = num[6][i][N - 1] = c;
        }
    //7
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j)
            if (j == N - 1 || i == 0)
                num[7][i][j] = c;
    //8
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (i == 0) num[8][i][j] = c;
            if (i == M / 2) num[8][i][j] = c;
            if (i == M - 1) num[8][i][j] = c;
            else num[8][i][0] = num[8][i][N - 1] = c;
        }
    //9
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j) {
            if (i == 0) num[9][i][j] = c;
            if (i == M / 2) num[9][i][j] = c;
            if (i == M - 1) num[9][i][j] = c;
            if (i < M / 2) num[9][i][N - 1] = num[9][i][0] = c;
            else num[9][i][N - 1] = c;
        }
}

Printer::~Printer() {
    ans.clear();
    plus.clear();
    minus.clear();
    bracket1.clear();
    bracket2.clear();
    minus.clear();
    equal.clear();
    mul.clear();
    div.clear();
    binom.clear();
    fclose(pic);
}

void Printer::changeSize(size_t x) {
    for (int j = 0; j < M; ++j)
        ans[j].resize(x, ' ');
}

void Printer::putChar(char ch) {
    if (isdigit(ch)) {
        putInt(ch - '0');
        return;
    }
    switch (ch) {
        case '+':
            putAns(plus, 0, M, size);
            break;
        case '-':
            putAns(minus, 0, M, size);
            break;
        case '(':
            putAns(bracket1, 0, M, size);
            break;
        case ')':
            putAns(bracket2, 0, M, size);
            break;
        case '=':
            putAns(equal, 0, M, size);
            break;
        case '*':
            putAns(mul, 0, M, size);
            break;
        case '/':
            putAns(div, 0, M, size);
            break;
        case 'c':
            putAns(binom, 0, M, size);
            break;
        case 'C':
            putAns(binom, 0, M, size);
            break;
        default:
            break;
    }
    size++;
}

int Printer::size_ans() {
    return size;
}

void Printer::putInt(int v) {
    if (v < 0) {
        putAns(minus, 0, M, size);
        v = -v;
        size--;
    }
    if (v == 0) {
        putAns(num[0], 0, M, size);
        return;
    }
    vector<int> x;
    while (v > 0) {
        x.push_back(v % 10);
        v /= 10;
    }
    /*if ((x.size()*(N + 3) + size) / 80 != size / 80)
    {
    size = ((x.size() * (N + 3) + size) / 80) * 80 + 1;
    if (ans[0].length() - 1 < size) changeSize();
    }
    */
    while (!x.empty()) {
        int i = x[x.size() - 1];
        putAns(num[i], 0, M, size);
        x.pop_back();
    }
    size++;
}

void Printer::printConsole() {
    for (int k = 0; k < size / 80 + 1; ++k) {
        for (int i = 0; i < M; ++i) {
            for (int j = k * 80; j < (k + 1) * 80 - 1 && j < size - 1; ++j)
                cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
}

void Printer::printPicture() {
    int r = 20;
    int k = 5;
    //y-height x-length
    int x = ans[0].length() * r, y = M * r;
    int mx = (x + 3) & (-4);

    char biType1 = 'B';
    char biType2 = 'M';
    unsigned int biSize = mx * y;
    unsigned int biReserved = 0;
    unsigned int bfOffBits = 26;

    unsigned int bcSize = 12;
    unsigned short int bcWidth = x;
    unsigned short int bcHeigh = y + 2 * k;
    unsigned short int bcPlanes = 1;
    unsigned short int bcBitCount = 24;

    FILE *f = pic;

    fwrite(&biType1, sizeof(char), 1, f);
    fwrite(&biType2, sizeof(char), 1, f);
    fwrite(&biSize, sizeof(unsigned int), 1, f);
    fwrite(&biReserved, sizeof(unsigned int), 1, f);
    fwrite(&bfOffBits, sizeof(unsigned int), 1, f);
    fwrite(&bcSize, sizeof(unsigned int), 1, f);
    fwrite(&bcWidth, sizeof(unsigned short int), 1, f);
    fwrite(&bcHeigh, sizeof(unsigned short int), 1, f);
    fwrite(&bcPlanes, sizeof(unsigned short int), 1, f);
    fwrite(&bcBitCount, sizeof(unsigned short int), 1, f);

    struct colour {
        char blue;
        char red;
        char green;
    };

    const auto ff = static_cast<const char>(255);
    colour yellow = {0, ff, ff};
    colour black = {0, 0, 0};
    colour white = {ff, ff, ff};

    for (int j = 0; j < k; j++)
        for (int i = 0; i < x; i++)
            fwrite(&yellow, sizeof(colour), 1, pic);

    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x / r; i++) {
            if (ans[M - 1 - j / r][i] != ' ') {
                for (int e = 0; e < r; ++e)
                    fwrite(&black, sizeof(colour), 1, pic);
            } else {
                for (int e = 0; e < r; ++e)
                    fwrite(&yellow, sizeof(colour), 1, pic);
            }
        }
    }

    for (int j = 0; j < k; j++)
        for (int i = 0; i < x + 1; i++)
            fwrite(&yellow, sizeof(colour), 1, pic);

}


void Printer::putAns(vector<string> a, int x1, int x2, size_t y) {
    if ((a[0].length() + y) / 80 != size / 80) {
        y = size = ((a[0].length() + y) / 80) * 80;
    }

    int x = a[0].length();
    if (ans[0].length() < y + x) changeSize(y + x + 1);
    for (int j = x1; j < x2; ++j) {
        for (int i = y; i < x + y; ++i) {
            ans[j][i] = a[j - x1][i - y];
        }
    }
    size += x + 2;
}

void Printer::print_str(string s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') continue;
        if (isdigit(s[i])) {
            int val = 0;
            while (isdigit(s[i])) {
                val = val * 10 + s[i] - '0';
                i++;
            }
            i--;
            putInt(val);
        } else if (s[i] != ',' && s[i] != 'c' && s[i] != 'C') putChar(s[i]);
        else if (s[i] == 'C' || s[i] == 'c') {
            putChar(s[i]);
            while (s[i] != '(') i++;
            i++;
            int j = i, b1 = 0, b2 = 0;
            while (i < s.length()) {
                if (s[i] == '(') b1++;
                if (s[i] == ')') b2++;
                if (s[i] == ',' && b2 - b1 == 0) break;
                i++;
            }
            string st1, st2;
            st1 = s.substr(j, i - j);
            j = i;
            b1 = b2 = 0;
            while (i < s.length()) {
                if (s[i] == '(') b1++;
                if (s[i] == ')') b2++;
                if (b2 - b1 == 1) break;
                i++;
            }
            st2 = s.substr(j + 1, i - j);
            st2.pop_back();

            Printer n1(M / 2);
            n1.print_str(st2);
            putAns(n1.ans, 0, M / 2, size);
            size -= n1.size_ans();
            Printer n2(M / 2);
            n2.print_str(st1);
            putAns(n2.ans, M / 2 + 1, M, size);
            size -= n2.size_ans();
            size += max(n2.size_ans(), n1.size_ans()) - 1;
        }
    }
}