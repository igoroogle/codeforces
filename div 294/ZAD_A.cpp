#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cctype>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
int main ()
    {
        char c;
        int a = 0,b = 0,i,j;
        for (i=0;i<8;i++)
            for (j=0;j<8;j++)
                {
                    cin >> c;
                    if (c == 'Q') a+=9;
                    else if (c == 'R') a+=5;
                    else if (c == 'B') a+=3;
                    else if (c == 'N') a+=3;
                    else if (c == 'P') a+=1;
                    else if (c == 'B') a+=3;
                    else if (c == 'q') b+=9;
                    else if (c == 'r') b+=5;
                    else if (c == 'b') b+=3;
                    else if (c == 'n') b+=3;
                    else if (c == 'p') b+=1;
                    else if (c == 'b') b+=3;
                }
        if (a > b) cout << "White" << endl;
        else if (a < b) cout << "Black" << endl;
        else cout << "Draw" << endl;
        return 0;
    }
