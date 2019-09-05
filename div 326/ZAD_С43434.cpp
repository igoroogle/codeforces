#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 5000310;
int a[DL];
bool del(ll v);
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, n, x, ans = 0;
    cin >> n;
    while(cin >> x)
    {
        cin >> x;
        a[x]++;
    }
    for (i = 0; i < DL - 2; i++)
    {
        ans += a[i] % 2;
        a[i + 1] += a[i] / 2;
    }

    cout << ans << endl;
    return 0;
}
