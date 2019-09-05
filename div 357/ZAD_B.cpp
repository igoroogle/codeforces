#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
const ll fr = 1234567;
const ll sc = 123456;
const ll th = 1234;
typedef long double ld;
char s[100010];
int main()
{
    ll n, a, b, c;
    cin >> n;
    for (a = 0; a * fr <= n; a++)
        for (b = 0; a * fr + b * sc <= n; b++)
            if ((n - a * fr - b * sc) % th == 0)
            {
                cout << "YES\n";
                return 0;
            }
    cout << "NO\n";
    return 0;
}
