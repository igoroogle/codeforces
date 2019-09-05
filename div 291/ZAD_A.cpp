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
bool bl[1010];
ll x[1010],y[1010];
int main ()
    {
        ll n,x0,y0,xt,yt,pz,kz,i,j,a,b,c,a1,b1,c1,ss = 0;
        cin >> n >> x0 >> y0;
        for (i=0;i<n;i++) bl[i] = 1;
        for (i=0;i<n;i++) scanf("%I64d%I64d",&x[i],&y[i]);
        for (i=0;i<n;i++)
            if (bl[i])
                {
                    ss++;
                    a = y0 - y[i];
                    b = x[i] - x0;
                    c = - (a*x0+b*y0);
                    xt = -(y[i] - y0)+y0;
                    yt = (x[i] - x0) + x0;
                    a1 = y0 - yt;
                    b1 = xt - x0;
                    c1 = - (a*x0+b*y0);
                    pz = x[i]*a1+y[i]*b1+c1;
                    if (pz != 0) pz/=abs(pz);
                    for (j=0;j<n;j++)
                        {
                            kz = x[j]*a1+y[j]*b1+c1;
                            if (kz != 0) kz/=abs(kz);
                            if ( ( a*x[j]+b*y[j]+c == 0) && (1) ) bl[j] = 0;
                        }
                }
        cout << ss << endl;
        return 0;
    }
