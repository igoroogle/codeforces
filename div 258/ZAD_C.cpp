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
ll a[100010];
int main ()
    {
        ll t,n,k,d1,d2,i,j,p,dd1,dd2,dd3,k1,dd;
        bool f;
        cin >> t;
        for (i=0;i<t;i++)
            {
                scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
                f = 0;
                for (j=0;j<2;j++)
                    for (p=0;p<2;p++)
                        {
                            dd1 = 0;
                            if (j) dd2 = dd1 + d1;
                            else dd2 = dd1 - d1;
                            if (p) dd3 = dd2 + d2;
                            else dd3 = dd2 - d2;
                            if (dd1 > dd2) swap(dd1,dd2);
                            if (dd2 > dd3) swap(dd2,dd3);
                            if (dd1 > dd2) swap(dd1,dd2);
                            dd = dd2 - dd1 + dd3 - dd1;
                            if (dd > k) continue;
                            if ((k - dd) % 3) continue;
                            k1 = k;
                            k1+=dd2-dd1;
                            k1+=(dd3-dd2)*2;
                            if (k1 > n) continue;
                            if ((n - k1) % 3) continue;
                            f = 1;
                        }
                    if (f) printf("yes\n");
                    else printf("no\n");
            }
        return 0;
    }
