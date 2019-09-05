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
using namespace std;
ll gcd(ll,ll);
ll nkd(ll,ll);
ll a[2000100];
int main ()
    {
        ll n,x,y,nk,a1,b1,v1,v2,l,r,m,vl,xl,i;
        cin >> n >> x >> y;
        nk = nkd(x,y);
        a1 = nk / x;
        b1 = nk / y;
        v1 = a1;
        v2 = b1;
        for (i=0;i<2000100;i++) a[i] = -1;
        a[0] = 2;
        for (i=1;i<2000010;i++)
            {
                if (a[i] != -1) continue;
                if (v1 == v2)
                    {
                        a[i] = 2;
                        a[i+1] = 2;
                        v1+=a1;
                        v2+=b1;
                    }
                else if (v1 < v2)
                    {
                        a[i] = 0;
                        v1+=a1;
                    }
                else
                    {
                        a[i] = 1;
                        v2+=b1;
                    }
            }
        for (i=0;i<n;i++)
            {
                scanf("%I64d",&xl);
                l = 1;
                r = xl;
                while (l < r)
                    {
                        m = (l+r) / 2;
                        if (m*x+m*y < xl) l = m + 1;
                        else r = m;
                    }
                vl = xl - ( (l-1)*x+(l-1)*y );
                if (a[vl] == 0) printf("%Vanya\n");
                else if (a[vl] == 1) printf("Vova\n");
                else printf("Both\n");
            }
        return 0;
    }
ll gcd(ll a,ll b)
    {
        if (a == 0)  return b;
        else if (b == 0) return a;
        else return gcd(b,a%b);
    }
ll nkd (ll a, ll b)
    {
        return a/gcd(a,b)*b;
    }
