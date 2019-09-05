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
const double PI = 3.14159265358979311600;
using namespace std;
string s;
int main ()
    {
        cin >> s;
        int i,len = s.length();
        bool f1 = 0,f2 = 0;
        for (i=0;i<len-1;i++)
            if ( (s[i] == 'A') && (s[i+1] == 'B') && ((i+2 == len) || (s[i+2] != 'A')) )
                {
                    f1 = 1;
                    break;
                }
        for (i=0;i<len-1;i++)
            if ( (s[i] == 'B') && (s[i+1] == 'A') && ((i == 0) || (s[i-1] != 'A')) && ((i+2 == len) || (s[i+2] != 'B')) )
                {
                    f2 = 1;
                    break;
                }
        if ((f1) && (f2)) cout << "YES";
        else cout << "NO";
        return 0;
    }
