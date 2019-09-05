#include <bits/stdc++.h>
using namespace std;

//#define forn(i, n) for (int i = 0; i < n; i++)
//#define mp make_pair
//#define pb push_back
//#define sz(n) n.size()
//#define x first
//#define y second

typedef long long ll;

const int LEN = 5100, INF = 1000000;
ll n, ar[LEN], dp[LEN], t, cnt;

int main()
{
    //freopen("horses.in", "r", stdin);
    //freopen("horses.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    for (int i = 1; i < n; i++)
        dp[i] = INF;
    dp[0] = -1;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dp[i] < INF && ar[i] + (j - i) * (j - i + 1) / 2 <= ar[j])
                dp[j] = min(dp[j], dp[i] + 1);

    t = 1000000000000000;
    cnt = INF;

    for (int i = 0; i < n; i++)
        if (dp[i] < INF && (ar[i] + (n - i) * (n - i + 1) / 2 < t || (ar[i] + (n - i) * (n - i + 1) / 2 == t && cnt > dp[i] + 1)))
        {
            t = ar[i] + (n - i) * (n - i + 1) / 2;
            cnt = dp[i] + 1;
        }

    cout << t << " " << cnt;

    return 0;
}

/*

5
3 3 2 5 1
1 2
2 3
2 4
4 5


*/



