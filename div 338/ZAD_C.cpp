#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
string s, rs, t, ss, s1, s2;
int z[6010], val[6010], dp[6010], pr[6010];
const int INF = 2E9;
int main()
{
    cin >> s >> t;
    rs = s;
    int l = 0, r = -1, i, j, h = t.length(), mx = 0;
    reverse(rs.begin(), rs.end());
    int n = s.length(), m = t.length();
    for (j = 0; j < m; j++)
    {
        ss = t.substr(j, m - j) + "#" + s;
        l = 0, r = -1, h = ss.length(), mx = 0;
        z[0] = 0;
        for (i = 1; i < h; i++)
        {
            z[i] = 0;
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while ((i + z[i] < h) && (ss[z[i]] == ss[i + z[i]]))
                z[i]++;
            if (i > m - i)
                mx = max(z[i], mx);
            if (r < i + z[i] - 1)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }

        ss = t.substr(j, m - j) + "#" + rs;
        l = 0, r = -1, i, h = ss.length();
        z[0] = 0;
        for (i = 1; i < h; i++)
        {
            z[i] = 0;
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while ((i + z[i] < h) && (ss[z[i]] == ss[i + z[i]]))
                z[i]++;
            if (i > m - i)
                mx = max(z[i], mx);
            if (r < i + z[i] - 1)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
        val[j] = mx;
    }

    for (i = m - 1; i >= 0; i--)
    {
        if (val[i] == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        dp[i] = INF;
        for (j = i; j < i + val[i]; j++)
        {
            if (j + 1 >= m)
                {
                    dp[i] = 1;
                    pr[i] = j;
                }
            else if (dp[j + 1] + 1 < dp[i])
            {
                dp[i] = dp[j + 1] + 1;
                pr[i] = j;
            }
        }
    }

    i = 0;
    int l1, l2;
    cout << dp[0] << endl;
    while (i < m)
    {
        l1 = s.find(t.substr(i, pr[i] - i + 1), 0);
        l2 = rs.find(t.substr(i, pr[i] - i + 1), 0);
        if ((l1 < n) && (l1 >= 0))
            printf("%d %d\n", l1 + 1, l1 + pr[i] - i + 1);
        else
            printf("%d %d\n", n - l2, n - (l2 + pr[i] - i));
        i = pr[i] + 1;
    }
    return 0;
}
