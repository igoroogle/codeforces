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
ll a[100010];
int main ()
    {
        ll n,i,l,r,f = 1;
        cin >> n;
        for (i=0;i<n;i++) scanf("%I64d",&a[i]);
        while ( (f < n) && (a[f] > a[f-1]) ) f++;
        if (f >= n)
            {
                cout << "yes\n1 1\n";
                return 0;
            }
        l = f-1;
        while ( (f < n) && (a[f] < a[f-1]) ) f++;
        r = f -1;
        reverse(a+l,a+r+1);
        f = 1;
        while ( (f < n) && (a[f] > a[f-1]) ) f++;
        if (f >= n) cout << "yes\n" << l+1 << ' ' << r+1 << endl;
        else cout << "no\n";
        return 0;
    }
