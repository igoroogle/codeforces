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
const int dl = 1000010;
using namespace std;
int prv[dl],first[dl],last[dl],a[100010];
int main ()
    {
        int n,i,mx = 0;
        cin >> n;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (i=0;i<dl;i++)
            {
                prv[i] = 0;
                first[i] = dl;
                last[i] = -1;
            }
        for (i=0;i<n;i++)
            {
                prv[a[i]]++;
                if (first[a[i]] > i) first[a[i]] = i;
                if (last[a[i]] < i) last[a[i]] = i;
            }
        int l = 0,r = n-1;
        mx = 0;
        for (i=0;i<dl;i++)
            if (prv[i] > mx) mx = prv[i];
        for (i=0;i<dl;i++)
            if ( (prv[i] == mx) && (last[i]-first[i]<r-l) )
                {
                    l = first[i];
                    r = last[i];
                }
        cout << l+1 << ' ' << r+1 << endl;
        return 0;
    }
