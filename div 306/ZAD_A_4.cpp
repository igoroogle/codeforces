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
const int inf = 1000100;
using namespace std;
string s;
int main ()
    {
        cin >> s;
        int a,b,len = s.length();
        a = s.find("AB",0);
        b = s.find("BA",0);
        if (a < 0) a = inf;
        if (b<0) b = inf;
        if (max(a,b) < len)
            {
                if (a < b)
                    {
                        if ( (s.find("BA",a+2) < len) && (s.find("BA",a+2) >= 0) ) cout << "YES" << endl;
                        else cout << "NO" << endl;
                    }
                else
                    {
                        if ( (s.find("AB",b+2) < len) && (s.find("AB",b+2) >= 0) ) cout << "YES" << endl;
                        else cout << "NO" << endl;
                    }
            }
        else cout << "NO" << endl;
        return 0;
    }
