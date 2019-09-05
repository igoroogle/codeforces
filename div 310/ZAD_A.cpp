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
string s;
int main ()
    {
        ll a = 0,b = 0,n,i;
        cin >> n >> s;
        for (i=0;i<n;i++)
            {
                if (s[i] == '0') a++;
                else b++;
            }
        cout << max(a,b) - min(a,b) << endl;
        return 0;
    }
