#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll n, a, b, c, mn;
    cin >> n >> a >> b >> c;
    if (n < b)
        cout << n / a << endl;
    else
    {
        mn = n / a;
        mn = max((n - c) / (b - c) + (((n - c) % (b - c) + c) / a), mn);
        cout << mn << endl;
    }
    return 0;
}
