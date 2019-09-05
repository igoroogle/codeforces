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
#include <map>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
const ll md = 1000000007;
using namespace std;
int main ()
    {
        ll d1 = 0, d2 = 0, d3 = 0, dd1,dd2,dd3,mn1,mx1,mn2,mx2,mn3,mx3,n,i;
        cin >> n >> mn1 >> mx1 >> mn2 >> mx2 >> mn3 >> mx3;
        for (i=mn1;i<=mx1;i++)
            if  (n-i >= mn2+mn3)
                {
                    dd1 = i;
                    dd2 = n - i - mn3;
                    if (dd2 > mx2) dd2 = mx2;
                    dd3 =n - dd1 - dd2;
                    if ( (dd3 >= mn3) && (dd3 <= mx3) )
                        {
                            d1 = dd1;
                            d2 = dd2;
                            d3 = dd3;
                        }
                }
        cout << d1 <<  ' ' << d2 << ' ' << d3 << endl;
        return 0;
    }
