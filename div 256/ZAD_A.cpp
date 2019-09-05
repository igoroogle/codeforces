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
int main ()
    {
        ll a1,a2,a3,b1,b2,b3,n,s;
        cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
        s = (a1+a2+a3)/5;
        if ((a1+a2+a3)%5) s++;
        s += (b1+b2+b3)/10;
        if ((b1+b2+b3)%10) s++;
        if (n >= s) cout << "YES\n";
        else cout << "NO\n";
        return 0;
    }
