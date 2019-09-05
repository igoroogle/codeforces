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
const ll md = 1000000007;
using namespace std;
int main ()
    {
        ll x,y,z,n,i;
        cin >> x >> y >> n;
        n--;
        n %= 6;
        x = (x + md) % md;
        y = (y + md) % md;
        if (n == 0) z = x;
        else if (n == 1) z = y;
        for (i=2;i<=n;i++)
            {
                z = (y + md - x) % md;
                x = y;
                y = z;
            }
        cout << z << endl;
        return 0;
    }
