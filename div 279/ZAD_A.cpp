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
ll a[5010],b[5010],c[5010];
int main ()
    {
        ll n,i,kl1 = 0,kl2 = 0,kl3 = 0,x;
        cin >> n;
        for (i=0;i<n;i++)
            {
                scanf("%I64d",&x);
                if (x == 1)
                    {
                        kl1++;
                        a[kl1-1] = i+1;
                    }
                else if (x == 2)
                    {
                        kl2++;
                        b[kl2-1] = i+1;
                    }
                else
                    {
                        kl3++;
                        c[kl3-1] = i+1;
                    }
            }
        cout << min(kl1,min(kl2,kl3)) << endl;
        for (i=0;i<min(kl1,min(kl2,kl3));i++)
            printf("%I64d %I64d %I64d\n",a[i],b[i],c[i]);
        return 0;
    }
