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
ll a[1010],n,l;
bool prov(double);
int main ()
    {
        ll i;
        double lk,rr,mm;
        cin >> n >> l;
        for (i=0;i<n;i++) scanf("%I64d",&a[i]);
        sort(a,a+n);
        //for (i=0;i<n;i++) cout << a[i] << endl;
        lk = 0;
        rr = 10000000000.0;
        for (i=0;i<10000;i++)
            {
                mm = (lk + rr) / 2.0;
                if (prov(mm)) lk = mm;
                else rr = mm;
            }
        printf("%.20lf\n",lk);
        return 0;
    }
bool prov(double x)
    {
        ll i;
        bool f = 0;
        for (i=1;i<n;i++)
            if (x*2 < a[i] - a[i-1])
                {
                    f = 1;
                    break;
                }
        if (x < a[0]) f = 1;
        if (x < l - a[n-1]) f = 1;
        return f;
    }
