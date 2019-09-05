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
ll c[1010],d[1010];
int main ()
    {
        ll n,i,k = 0;
        cin >> n;
        for (i=0;i<n;i++) scanf("%I64d",&c[i]);
                d[0] = ((1+c[0])*c[n-2] / 2) % md;
                k+=d[0] % md;
        for (i=1;i<n;i++)
            {
                d[i] = ((1+c[i])*c[i] / 2) * (k+1) % md;
                k+=d[i] % md;
            }
        cout << k << endl;
        return 0;
    }
