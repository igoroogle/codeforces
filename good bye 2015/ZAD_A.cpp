#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
const ll a[] = {31,29,31,30,31,30,31,31,30,31,30,31};
typedef long double ld;
string s;
int main()
{
    ll n, m, ms = 0, km = 0, d = 4, ans = 0;
    cin >> n >> s >> s;
    n--;
    if (s == "week")
    {
        while (ms < 12)
        {
            if (d == n)
                ans++;
            d = (d + 1) % 7;
            if (km + 1 < a[ms])
                km++;
            else
            {
                ms++;
                km = 0;
            }
        }
    }
    else
    {
        while (ms < 12)
        {
            if (km == n)
                ans++;
            d = (d + 1) % 7;
            if (km + 1 < a[ms])
                km++;
            else
            {
                ms++;
                km = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
