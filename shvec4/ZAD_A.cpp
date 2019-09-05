#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 200010;
ll prv[DL], nxt[DL], val[DL];
map <ll, ll> a;
int main()
{
    ll n, i, x, y, cnt = 0, u, v;
    cin >> n;

    for (i = 0; i < DL; i++)
    {
        prv[i] = -1;
        nxt[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        scanf ("%I64d%I64d", &x, &y);
        u = a[x];
        if (!u)
        {
            cnt++;
            val[cnt] = x;
            a[x] = cnt;
            u = cnt;
        }
        v = a[y];
        if (!v)
        {
            cnt++;
            val[cnt] = y;
            a[y] = cnt;
            v = cnt;
        }

        if (prv[u] == -1)
            prv[u] = v;
        else
            nxt[u] = v;
        if (prv[v] == -1)
            prv[v] = u;
        else
            nxt[v] = u;
    }

    u = -1;
    v = 1;
    for(;;)
    {
        if ((prv[v] != -1) && (prv[v] != u))
        {
            u = v;
            v = prv[v];
        }

        else if ((nxt[v] != -1) && (nxt[v] != u))
        {
            u = v;
            v = nxt[v];
        }
        else
            break;
    }

    u = -1;
    for(;;)
    {
        printf("%I64d ", val[v]);
        if ((prv[v] != -1) && (prv[v] != u))
        {
            u = v;
            v = prv[v];
        }

        else if ((nxt[v] != -1) && (nxt[v] != u))
        {
            u = v;
            v = nxt[v];
        }
        else
            break;
    }
    return 0;
}
