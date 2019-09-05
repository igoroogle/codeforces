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
ll pw[1010],pwt[1010],d[1003][103],n,k,m;
int main ()
    {
        ll i,j,p,ans = 0,z,t,f;
        cin >> n >> k >> m;
        pw[0] = 1 % m;
        for (i=1;i<1010;i++) pw[i] = (pw[i-1]*10)%m;
        pwt[0] = 1 % k;
        for (i=1;i<1010;i++) pwt[i] = (pwt[i-1]*10)%k;
        for (i=0;i<=n;i++)
            for (j=0;j<=k;j++) d[i][j] = 0;
        d[0][0] = 1;
        for (i=1;i<n;i++)
            for (j=0;j<=9;j++)
                for (p=0;p<k;p++)
                    {
                        if (((j*pwt[i-1]+p) % k)) d[i][(j*pwt[i-1]+p) % k] = (d[i][(j*pwt[i-1]+p) % k] + d[i-1][p]) % m;
                        else  ans = (ans + d[i-1][p]*pw[n-i]) % m;
                    }
        for (j=1;j<=9;j++)
                for (p=0;p<k;p++)
                    if (!((j*pwt[n-1]+p) % k)) ans = (ans + d[n-1][p]) % m;
        cout << ans << endl;
        return 0;
    }
