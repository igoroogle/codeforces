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
const ll dl = 100010;
using namespace std;
ll a[dl],s[dl];
bool smx[dl];
int main ()
    {
        ll n,i,j,mx,dv,ans = 0,sk,kr;
        cin >> n;
        for (i=0;i<n;i++) scanf("%I64d",&a[i]);
        for (i=0;i<dl;i++)
            {
                s[i] = 0;
                smx[i] = 1;
            }
        for (i=0;i<n;i++)
            {
                j = a[i];
                while (j > 0)
                    {
                        if (j%2) s[j]++;
                        j/=2;
                    }
            }
        mx = 1;
        for (j=dl-1;j>0;j--)
            if (s[j] == n)
                {
                    mx = j;
                    break;
                }
        dv = mx;
        while (dv < dl)
            {
                smx[dv] = 0;
                dv+=dv;
            }
        for (i=0;i<n;i++)
            {
                j = a[i];
                while (smx[j])
                    {
                        j/=2;
                        ans++;
                    }
                a[i] = j;
            }
        ll msk = 1000000000000000000;
        dv = mx;
        while (dv < dl)
            {
                sk = 0;
                for (i=0;i<n;i++)
                    {
                        j = a[i];
                        while (j > dv)
                            {
                                sk++;
                                j/=2;
                            }
                        while (j < dv)
                            {
                                sk++;
                                j*=2;
                            }
                    }
                if (sk < msk) msk = sk;
                dv*=2;
            }
        cout << ans + msk << endl;
        return 0;
    }
