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
ll a[1000100],b[1000100];
string s;
int main ()
    {
        cin >> s;
        ll n = s.length(),i,a1,b1,k = 0;
        cin >> a1 >> b1;
        a[0] = 0;
        for (i=1;i<=n;i++) a[i] = (a[i-1] * 10 + ll(s[i-1] -'0')) % a1;
        b[0] = 1;
        for (i=1;i<=n;i++) b[i] = (b[i-1]*10) % b1;
        for (i=n-1;i>0;i--)
                {
                   k = ( ( (b[n-i-1] * ll(s[i] -'0')) % b1) + k)  % b1;
                   if ( (a[i] == 0) && (k == 0) &&  (s[i] != '0') )
                        {
                            cout << "YES\n";
                            cout << s.substr(0,i) << endl;
                            cout << s.substr(i,n-i) << endl;
                            return 0;
                        }
                }
        cout << "NO" << endl;
        return 0;
    }
