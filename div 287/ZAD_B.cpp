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
bool b[110];
ll ans[100010],a[100010];
int main ()
    {
        ll x1,y1,x2,y2,r,rst,ras,ans = 0;
        double rs;
        cin >> r >> x1 >> y1 >> x2 >> y2;
        if ( (x1 == x2) && (y1 == y2) ) cout << 0 << endl;
        else
            {
                ras =  (x1 -x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                rs = sqrt(double(ras));
                rst = ll(rs);
                if (rst*rst < ras) rst++;
                r*=2;
                while (rst > 0)
                    {
                        rst-=r;
                        ans++;
                    }
                if (ans == 0) ans++;
                cout << ans << endl;
            }
        return 0;
    }
