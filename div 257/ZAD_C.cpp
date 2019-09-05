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
        ll n,m,k;
        cin >> n >> m >> k;
        if (n < m) swap(n,m);
        if (n+m-2 < k) cout << -1 << endl;
        else if (k < n) cout << n/(k+1)*m << endl;
        else cout << k+2-n << endl;
        return 0;
    }
