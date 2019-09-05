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
using namespace std;
ll a[200010],b[200010];
int main ()
    {
        ll s1 = 0,s2 = 0,n,i,x,ff = -1,kl1 = 0,kl2 = 0;
        bool f2 = 0;
        cin >> n;
        for (i=0;i<n;i++)
            {
                scanf("%I64d",&x);
                if (x > 0)
                    {
                        s1+=x;
                        f2 = 1;
                        kl1++;
                        a[kl1-1] = x;
                    }
                else
                    {
                        s2+=-x;
                        f2 = 0;
                        kl2++;
                        b[kl2-1] = -x;
                    }
            }
        for (i=0;i<min(kl1,kl2);i++)
            if (a[i] != b[i])
                {
                    if (a[i] > b[i]) ff =1;
                    else ff = 0;
                    break;
                }
        if ( (s1 > s2) || ((s1 == s2) && (ff == 1)) || ((s1 == s2) && (ff == -1) && (f2)) ) cout << "first";
        else cout << "second";
        return 0;
    }
