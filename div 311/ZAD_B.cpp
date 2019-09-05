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
ll a[200010];
int main ()
    {
        ll n,w,i;
        double vl;
        cin >> n >> w;
        for (i=0;i<n+n;i++) scanf("%I64d",&a[i]);
        sort(a,a+n+n);
        if (a[0]*2 <= a[n]) vl = double(a[0]);
        else vl = double(a[n])/2.0;
        if (vl*3.0*double(n) > w) vl = w;
        else vl = vl*3.0*double(n);
        printf("%.10lf\n",vl);
        return 0;
    }
