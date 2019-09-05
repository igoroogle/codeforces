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
ll a[100010];
int main ()
    {
        ll n,i,j,v,t;
        cin >> n;
        for (i=0;i<n;i++) scanf("%I64d",&a[i]);
        sort(a,a+n);
        t = 0;
        v = 0;
        for (i=0;i<n;i++)
            {
                if (t <= a[i])
                    {
                        v++;
                        t+=a[i];
                    }
            }
        cout << v << endl;
        return 0;
    }
