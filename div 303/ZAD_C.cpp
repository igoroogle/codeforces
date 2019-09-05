#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
ll x[100010],h[100010],d[100011];
int main ()
    {
        ll n,i,j,v,t,l,r,m,l1,l2;
        cin >> n;
        for (i=1;i<=n;i++) scanf("%I64d%I64d",&x[i],&h[i]);
        x[n+1] = 2000000010;
        h[n+1] = 0;
        n+=2;
        x[0] = -2000000010;
        h[0] = 0;
        for (i=0;i<n;i++) d[0] = 0;
        for (i=1;i<n-1;i++)
            {
                if (d[i-1] > d[i]) d[i] = d[i-1];
                l = 0;
                r = i;
                while (l < r)
                    {
                        m = (l+r) / 2;
                        if (x[m] < x[i]-h[i]) l = m + 1;
                        else r = m;
                    }
                l1 = l - 1;
                l = i;
                r = n-1;
                while (l < r)
                    {
                        m = (l+r) / 2;
                        if (x[i]+h[i] >= x[m]) l = m + 1;
                        else r = m;
                    }
                l2 = l;
                if (d[l1+1] + 1 > d[i+1]) d[i+1] = d[l1+1] + 1;
                if (d[i]+1>d[l2]) d[l2] = d[i] + 1;

                cout << l1 << " " << l2 << endl;
            }
        ll mx = 0;
        for (i=0;i<n;i++)
            if (d[i] > mx) mx = d[i];
        cout << mx << endl;
        return 0;
    }
