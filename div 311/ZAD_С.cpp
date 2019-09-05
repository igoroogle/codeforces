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
struct xy
    {
       ll l,d;
       /*xy operator=(xy b)
            {
                l = b.l;
                d = d.l;
            }*/
    };
bool compr(xy a,xy b)
    {
        if (a.l > b.l) return 1;
        else return 0;
    }
xy a[100010];
ll sm[203],ss[100010];
int main ()
    {
        ll n,i,j,l = 0,r = 0,mn = 1000000000,vl,sk;
        cin >> n;
        for (i=0;i<n;i++) scanf("%I64d",&a[i].l);
        for (i=0;i<n;i++) scanf("%I64d",&a[i].d);
        sort(a,a+n,compr);
        for (i=0;i<203;i++) sm[i] = 0;
        for (i=0;i<n;i++) sm[a[i].d]++;
        ss[0] = 0;
        for (i=1;i<=n;i++) ss[i] = ss[i-1] + a[i-1].d;
        a[n].l = -1;
        sm[a[0].d]--;
        for (i=1;i<=n;i++)
            {
                if (a[i].l != a[i-1].l)
                    {
                        r = i-1;
                        if (n - r - 1 > r-l) vl = n - r - 1 - (r-l);
                        else vl = 0;
                        sk = ss[l];
                        for (j=0;j<203;j++)
                            if ( (vl > 0) && (sm[j] > 0) )
                                {
                                    if (sm[j] < vl)
                                        {
                                            sk+=j*sm[j];
                                            vl-=sm[j];
                                        }
                                    else
                                        {
                                            sk+=vl*j;
                                            vl = 0;
                                            break;
                                        }
                                }
                        if (sk < mn) mn = sk;
                        l = i;
                    }
                if ( i < n ) sm[a[i].d]--;
            }
        cout << mn << endl;
        return 0;
    }
