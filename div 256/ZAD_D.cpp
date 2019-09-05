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
const double EPS = 1E-10;
const ll inf = 2000000010;
using namespace std;
int main ()
    {
        ll n,m,k,l,r,mm,i,j,z;
        cin >> n >> m >> k;
        l = 1;
        r = n*m+1;
        while (l<r)
            {
                z = 0;
                mm = (l+r) / 2;
                for (i=1;i<=n;i++)
                    {
                        j = mm / i;
                        if (j > m) j = m;
                        while (j*i >= mm) j--;
                        z+=j;
                    }
                if (z < k) l = mm+1;
                else r = mm;
            }
        cout << l-1 << endl;
        return 0;
    }
