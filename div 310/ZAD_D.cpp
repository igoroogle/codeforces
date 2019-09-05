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
typedef unsigned long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
const ll md = 1000000007;
using namespace std;
ll rec(ll);
struct xind
    {
        ll x,ind;
        bool operator<(xind b)
            {
                return (x < b.x);
            }
        xind operator=(xind b)
            {
                x = b.x;
                ind = b.ind;
            }
    };
struct lrind
    {
        ll l,r,ind;
        bool operator<(lrind b)
            {
                return ( (l < b.l) || ((l == b.l) && (r < b.r)) );
            }
        xind operator=(lrind b)
            {
                l = b.l;
                r = b.r;
                ind = b.ind;
            }
    };
bool comp1(xind a,xind b)
    {
        if (a<b) return 1;
        else return 0;
    }
bool comp2(lrind a,lrind b)
    {
        if (a<b) return 1;
        else return 0;
    }
xind a[200010];
ll cl[200010],cr[200010],ans[200010];
lrind b[200010];
int main ()
    {
        ll n,m,i,j,kl = 0;
        cin >> n >> m;
        for (i=0;i<n;i++) scanf("%I64d%I64d",&cl[i],&cr[i]);
        for (i=0;i<m;i++)
            {
                scanf("%I64d",&a[i].x);
                a[i].ind = i;
            }
        sort(a,a+m,comp1);
        for (i=0;i<n-1;i++)
            {
                kl++;
                b[kl-1].l = cl[i+1] - cr[i];
                b[kl-1].r = cr[i+1] - cl[i];
                b[kl-1].ind = i;
            }
        sort(b,b+kl,comp2);
        j = 0;
        for (i=0;i<kl;i++)
            {
                while (j < m)
                    {
                        if ( (a[j].x >= b[i].l) && (a[j].x <= b[i].r) ) break;
                        j++;
                    }
                if (j >= m)
                    {
                        printf("No\n");
                        return 0;
                    }
                ans[b[i].ind] = a[j].ind;
                j++;
            }
        printf("Yes\n");
        for (i=0;i<kl;i++) printf("%I64d ",ans[i]+1);
    }
