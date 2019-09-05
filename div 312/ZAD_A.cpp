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
pair<ll,ll> a[110];
ll sum[110];
int main ()
    {
        ll n,i,k1 = 0,k2 = 0,z = 0,l,r;
        cin >> n;
        for (i=0;i<n;i++) scanf("%I64d%I64d",&a[i].first,&a[i].second);
        sort(a,a+n);
        while ( (z < n) && (a[z].first < 0) ) z++;
        l = z - 1;
        r = z;
        i = l;
        while ( (i >=0) && (i < n) )
            {
                k1+=abs(a[i].second);
                if (a[i].first < 0)
                    {
                        l--;
                        i = r;
                    }
                else
                    {
                        r++;
                        i = l;
                    }
            }
        l = z - 1;
        r = z;
        i = r;
        while ( (i >=0) && (i < n) )
            {
                k2+=abs(a[i].second);
                if (a[i].first < 0)
                    {
                        l--;
                        i = r;
                    }
                else
                    {
                        r++;
                        i = l;
                    }
            }
        cout << max(k1,k2) << endl;
        return 0;
    }
