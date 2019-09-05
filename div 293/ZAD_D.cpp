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
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
double d[2010][2010];
int main ()
    {
        ll n,t,i,j;
        double p,mt = 0,sf;
        cin >> n >> p >> t;
        for (i=0;i<2010;i++)
            for (j=0;j<2010;j++) d[i][j] = 0;
        d[0][0] = 1.0;
        for (i=1;i<=t;i++)
            {
                sf = 0.0;
                for (j=0;j<min(n,t);j++)
                {
                    d[i][j] = d[i-1][j]*(1.0-p);
                    if (j-1 >=0) d[i][j]+=d[i-1][j-1]*p;
                    sf+=d[i][j];
                }
                d[i][min(n,t)] = 1.0 - sf;
            }
        for (i=0;i<=n;i++) mt+=d[t][i]*double(i);
        printf("%.20lf\n",mt);
        return 0;
    }
