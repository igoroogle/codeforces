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
ll d[1010][1010],dp[1010];
ll c[1010];
int main ()
    {
        ll i,j,k,sm=0;
        cin >> k;
        for (i=0;i<k;i++) scanf("%I64d",&c[i]);
        for (i=0;i<1010;i++)
            for (j=0;j<1010;j++)
                {
                    if (j==0) d[i][j] == 1;
                    else d[i][j] = ((i+j-1) * d[i][j-1]) % md;
                }
        dp[0] = c[0] % md;
        sm = c[0];
        for (i=1;i<k;i++)
            {
                dp[i] = 0;
                for (j=0;j<c[i];j++) dp[i]+=(dp[i-1]*d[sm][j]) % md;
                sm+=c[i];
            }
        cout << dp[k-1] << endl;
        return 0;
    }
