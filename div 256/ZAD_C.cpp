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
ll d[5010][5010],a[5010],dp[5010];
int main ()
    {
        ll n,i,j,z;
        cin >> n;
        for (i=0;i<n;i++) scanf("%I64d",&a[i]);
        for (i=0;i<=n;i++) d[0][i] = i;
        dp[0] = 0;
        for (i=1;i<=n;i++)
            {
                dp[i] = dp[i-1] + 1;
                if ( (a[i-1] <= n) && (d[i-1][a[i-1]] < dp[i]) ) dp[i] = d[i-1][a[i-1]];
                for (j=0;j<=n;j++)
                    {
                        if (j < a[i-1]) d[i][j] = d[i-1][j] + 1;
                        else if (j == a[i-1]) d[i][j] = d[i-1][j];
                        else d[i][j] = j + dp[i];
                    }
            }
        cout << dp[n] << endl;
        return 0;
    }
