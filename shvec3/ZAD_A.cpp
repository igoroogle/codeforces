#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i, j, n, sm = 0;
    cin >> n;
    for (i = 1; i <= n / 2; i++)
        for (j = i; j <= n / 2; j++)
            sm++;
    cout << sm << endl;
    return 0;
}
