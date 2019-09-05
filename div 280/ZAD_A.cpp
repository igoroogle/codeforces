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
using namespace std;
int main ()
    {
        ll n,i,mx = 0,sm = 0;
        cin >> n;
        for (i=1;i<=n;i++)
            {
                sm+=i;
                if (n >= sm) n-=sm;
                else break;
                mx++;
            }
        cout << mx << endl;
        return 0;
    }
