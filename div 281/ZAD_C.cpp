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
ll a[200010],b[200010];
int main ()
    {
        ll s = -inf, f = 0,l = 0,n,m,ff = 0,lt = 0,fs,ls,i,mx;
        cin >> n;
        for (i=0;i<n;i++) scanf("%I64d",&a[i]);
        cin >> m;
        for (i=0;i<m;i++) scanf("%I64d",&b[i]);
        sort(a,a+n);
        sort(b,b+m);
        a[n] = inf;
        b[m] = inf;
        mx = 0;
        while (mx < inf)
            {;
                while (a[ff] <= mx) ff++;
                while (b[lt] <= mx) lt++;
                fs = ff*2 + (n - ff) * 3;
                ls = lt*2 + (m - lt) * 3;
                if ( (fs - ls > s) || ((fs - ls == s) && (fs > f)) )
                    {
                        s = fs - ls;
                        f = fs;
                        l = ls;
                    }
                mx = min(a[ff],b[lt]);
            }
        printf("%I64d:%I64d\n",f,l);
        return 0;
    }
