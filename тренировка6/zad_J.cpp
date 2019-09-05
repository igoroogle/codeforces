#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
/*#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define sz(n) n.size()
#define x first
#define y second*/

const ll P = 12737, MOD = 123133173;
string st;
ll n, ar[1000], dist, h[2000200], m, cnt, step[2000200];

ll get(int l, int r)
{
    ll res = h[r];
    if (l > 0)
        res = (res + MOD - ((h[l - 1] * step[r - l + 1]) % MOD)) % MOD;
    return res;
}

int main()
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    cin >> st;
    n = st.size();

    step[0] = 1;
    for (int i = 1; i < 2 * n; i++)
        step[i] = (step[i - 1] * P) % MOD;

    for (char i = 'a'; i <= 'z'; i++)
    {
        dist = 0;
        for (int j = 0; j < n; j++)
            dist = max(dist, (ll)abs(i - st[j]));
        ar[i] = dist;
    }

    st = st + st;
    h[0] = st[0] - 'a' + 1;
    for (int i = 1; i < 2 * n; i++)
        h[i] = (h[i - 1] * P + st[i] - 'a' + 1) % MOD;

    m = 10000;
    for (int i = 0; i <= n; i++)
        m = min(ar[st[i]] + ar[st[i + n - 1]], m);

    if (ar[st[0]] + ar[st[n - 1]] == m)
        cnt++;
    for (int i = 1; i <= n; i++)
    {
        //cout << get(i, i + n - 1) << " " << get(0, n - 1) << endl;
        if (get(i, i + n - 1) == get(0, n - 1))
            break;
        else if (ar[st[i]] + ar[st[i + n - 1]] == m)
            cnt++;
    }
    cout << m << " " << cnt;

    return 0;
}

