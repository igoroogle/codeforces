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
struct xy
    {
        ll x,y;
    };
xy a[2010];
bool tr[210][210];
ll gcd(ll,ll);
int main ()
    {
        ll i,j,k,n,t,nd,xd,yd,s = 0,kl;
        cin >> n;
        for (i=0;i<210;i++)
            for (j=0;j<210;j++) tr[i][j] = 0;
        for (i=0;i<n;i++)
            {
                scanf("%I64d%I64d",&a[i].x,&a[i].y);
                tr[a[i].x+101][a[i].y+101] = 1;
            }
        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
                {
                    nd = gcd(a[j].x-a[i].x,a[j].y-a[i].y);
                    xd = (a[j].x-a[i].x) / nd;
                    yd = (a[j].y-a[i].y) / nd;
                    t = 0;
                    k = 0;
                    while ( (a[i].x+xd*t >= -101) && (a[i].x+xd*t <= 101) && (a[i].y+yd*t >= -101) && (a[i].y+yd*t <= 101) )
                        {
                            if (tr[a[i].x+xd*t+101][a[i].y+yd*t+101]) k++;
                            t--;
                        }
                    t = 1;
                    while ( (a[i].x+xd*t >= -101) && (a[i].x+xd*t <= 101) && (a[i].y+yd*t >= -101) && (a[i].y+yd*t <= 101) )
                        {
                            if (tr[a[i].x+xd*t+101][a[i].y+yd*t+101]) k++;
                            t++;
                        }
                    s+=n-k;
                }
        cout << s/3 << endl;
        return 0;
    }
ll gcd (ll a,ll b)
    {
        if (a == 0) return b;
        else if (b == 0) return a;
        else return gcd(b, a % b);
    }
