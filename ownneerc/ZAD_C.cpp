#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2000000010;
pair <ll, ll> a[100010];
ll b[100010], ans[100010];
int main()
{
    freopen("parties.in", "r", stdin);
    freopen("parties.out", "w", stdout);
    ll n, i, j, ind;
    cin >> n;
    for (i = 0; i < n; i++)
        {
            scanf("%I64d", &a[i].first);
            a[i].second = i;
        }
    sort(a, a + n);
    ind = n - 2;
    b[n - 1] = 2;
    ll typ = 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i].first > 0)
        {
            ind--;
            a[i].first--;
            b[i] = typ;
        }
        else
            break;
        if (typ == 2)
            typ = 1;
        else
            typ = 2;
    }
    ind++;
    for (i = ind + 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << "NO\n";
            return 0;
        }

        if ((a[i].first > 0) && (b[ind] != b[i]))
        {
            a[i].first--;
            break;
        }
    }

    i = 0;
    j = 1;
    while (b[i] == 0)
    {
        while (a[j].first == 0)
            j++;
        a[j].first--;
        if (b[j] == 1)
            b[i] = 2;
        else
            b[i] = 1;
        i++;
    }
    cout << "YES\n";
    for (i = 0; i < n; i++)
        ans[a[i].second] = b[i];
    for (i = 0; i < n; i++)
        printf("%I64d ", ans[i]);
    return 0;
}
