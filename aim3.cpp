#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (a < 0)
        a = c - (abs(a) % c);

    if (b < 0)
        b = c - (abs(b) % c);

    cout << (a + b) % c << endl;
    return 0;
}
