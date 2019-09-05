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
const ld EPS = 1E-10;
using namespace std;
bool prov(ld x);
bool mat(ld,ld,ld,ld);
ld a,b,c,d;
int main ()
    {
        ld l,r,m;
        cin >> a >> b >> c >> d;
        l = 0;
        r = 10000000000;
        while (r-l > EPS)
            {
                m = (l+r) / 2;
                if (prov(m)) l = m+1;
                else r = m ;
            }
        cout << fixed << setprecision(10) << l << endl;
        return 0;
    }
bool mat(ld a1,ld b1,ld c1,ld d1)
    {
        return (abs(a1*d1-b1*c1) < EPS );
    }
bool prov(ld x)
    {
        bool f = 1;
        int i,j,p;
        ld ak,bk,ck,dk;
        for (i=0;i<16;i++)
            {
                j = i;
                if (j%2) ak = a + x;
                else ak = a - x;
                j /= 2;
                if (j%2) bk = b + x;
                else bk = b - x;
                j /= 2;
                if (j%2) ck = c + x;
                else ck = c - x;
                j /= 2;
                if (j%2) dk = d + x;
                else dk = d - x;
                if (mat(ak,bk,ck,dk)) f = 0;
            }
        return f;
    }
