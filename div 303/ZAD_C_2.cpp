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
ll x[100010],h[100010],d[100011],hd[100011];
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
        hd[0] = x[0];
        d[0] = 0;
        for (i=0;i<n;i++) d[0] = 0;
        for (i=1;i<n-1;i++)
            {
                hd[i] = x[i];
                if (x[i] - h[i] > hd[i-1]) d[i] = d[i-1] + 1;
                else if (x[i] + h[i] < x[i+1])
                    {
                        d[i] = d[i-1] + 1;
                        hd[i] = x[i] + h[i];
                    }
                else d[i] = d[i-1];
            }
        ll mx = 0;
        cout << d[n-2] << endl;
        return 0;
    }
