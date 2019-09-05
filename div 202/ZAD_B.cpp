#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010], n;
void fun();
int main()
{
    ll l, r, m, i;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    fun();
    return 0;
}

void fun()
{
    ll i, sm = 0, ss = 0;
    for (i = 0; i < n; i++)
        sm += a[i];
    cout << max((sm - 1) / (n - 1) + 1, a[n - 1]);
}
