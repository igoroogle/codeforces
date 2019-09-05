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
ll lef[1000100],rig[1000100],a1[200010],a[200010],b[200010];
int main ()
    {
        ll n,i,x,y;
        cin >> n;
        for (i=0;i<1000100;i++)
            {
                lef[i] = -1;
                rig[i] = -1;
            }
        for (i=0;i<n;i++)
            {
                scanf("%I64d%I64d",&x,&y);
                rig[x] = y;
                lef[y] = x;
                a[i] = x;
                b[i] = y;
            }
        a1[1] = rig[0];
        i = 1;
        while (a1[i] > 0)
            {
                a1[i+2] = rig[a1[i]];
                i+=2;
            }
        if (n%2)
            {
                for (i=0;i<n;i++)
                {
                    if ( (rig[b[i]] < 1) && (b[i] != a1[n-2]) )
                        {
                            a1[n-1] = b[i];
                            break;
                        }
                    if ( (rig[a[i]] < 1) && (a[i] != a1[n-2]) )
                        {
                            a1[n-1] = a[i];
                            break;
                        }
                }
                i = n-3;
                while (i >= 0)
                    {
                        a1[i] = lef[a1[i+2]];
                        i-=2;
                    }
            }
        else
            {
                for (i=0;i<n;i++)
                {
                    if ( (rig[b[i]] < 1) && (b[i] != a1[n-1]) )
                        {
                            a1[n-2] = b[i];
                            break;
                        }
                    if ( (rig[a[i]] < 1) && (a[i] != a1[n-1]) )
                        {
                            a1[n-2] = a[i];
                            break;
                        }
                }
                i = n-4;
                while (i >= 0)
                    {
                        a1[i] = lef[a1[i+2]];
                        i-=2;
                    }
            }
        for (i=0;i<n;i++) printf("%I64d ",a1[i]);
        return 0;
    }
