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
ll sk = 0;
class geom
    {
        public:
            ll a,b,c;
        bool operator<(geom p)
            {
                if ( (a < p.a) || ((a == p.a) && (b < p.a) ) || ((a == p.a) && (b == p.b) && (c < p.c)) ) return 1;
                else return 0;
            }
        bool operator==(geom p)
            {
                return (a == p.a) && (b == p.b) && (c == p.c) ;
            }
    };
struct xy
    {
        ll x,y;
    };
ll gcd (ll a,ll b)
    {
        if (a == 0) return b;
        else if (b == 0) return a;
        else return gcd(b,a % b);
    }
    int u;
bool comp(geom a1,geom b1)
    {
        if (u > 4)
            {
                sk++;
                if (sk > 1000000)
                    {
                        cout << 'opop' << endl;
                        exit(0);
                    }
            }
        if (a1 < b1) return 1;
        else return 0;
    }
xy a[2010];
geom b[5000100];
int main ()
    {
        int i,j,n,kol = 0;
        ll a1,b1,c1,nd;
        cin >> n;
        u = n;
        for (i=0;i<n;i++) scanf("%I64d%I64d",&a[i].x,&a[i].y);
        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
                if (i != j)
                    {
                        a1 = a[i].x - a[j].x;
                        b1 = a[j].y - a[i].x;
                        c1 = -(a1*a[i].x + b1*a[i].y);
                        if ( (a1 != 0) || (b1 != 0) || (c1 != 0) )
                            {
                                nd = gcd(gcd(a1,b1),c1);
                                a1/=nd;
                                b1/=nd;
                                c1/=nd;
                            }
                        kol++;
                        b[kol-1].a = a1;
                        b[kol-1].b = b1;
                        b[kol-1].c = c1;
                    }
        sort(b,b+kol,comp);
        /*if (n > 4)
            {
                cout << kol << endl;
                return 0;
            }*/
        b[kol].a = 10000;
        ll tt = 1,ss = 0,l,r,mm,prg,sk= 0;
        for (i=1;i<=kol;i++)
            {
                if (b[i] == b[i-1]) tt++;
                else
                    {
                        l = 1;
                        r = n+1;
                        while (l < r)
                            {
                                mm = (l+r) / 2;
                                prg = ll((double(mm)+1.0)/2.0*double(mm));
                                if (prg < tt) l = mm+1;
                                else r = mm;
                            }
                        ss+=tt*ll(ll(n)-l-1);
                        tt = 1;
                    }
            }
        cout << ss / 3 << endl;
        cout << "emm" << endl;
        return 0;
    }
