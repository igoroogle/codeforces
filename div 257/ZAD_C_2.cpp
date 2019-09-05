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
const ll md = 1000000007;
using namespace std;
int main ()
    {
        ll n,m,k,x,y,i,mx = 0;
        cin >> n >> m >> k;
        if (n > m) swap(n,m);
        if (n+m-2 < k)
            {
                cout << -1 << endl;
                return 0;
            }
        for (x=1;x<=2*ll(sqrt(double(m)))+2;x++)
            {
                if  ( ( k < x) && (n/x*m > mx) ) mx = n/x*m;
                else if ( (k - x + 2 > 0) && ((n/x) * (m/(k - x + 2)) > mx) ) mx = (n/x) * (m/(k - x + 2));
                if  ( ( (k < n/x) && (n/(n/x)*m > mx) ) ) mx = n/(n/x)*m;
                else if ( (n/x > 0) && (k - (n/x) + 2 > 0) && ((n/(n/x)) * (m/(k - (n/x) + 2)) > mx) ) mx = (n/(n/x)) * (m/(k - (n/x) + 2));
            }
        //if ( (k <= m) && (n/(k-m+2) > mx) ) mx = n/(k-m+2);
        cout << mx << endl;
        return 0;
    }
