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
        ll n,m;
        cin >> n >> m;
        if (min(n,m)%2) cout << "Akshat\n";
        else cout << "Malvika\n";
        return 0;
    }
