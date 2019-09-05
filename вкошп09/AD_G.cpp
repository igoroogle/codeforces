#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>


using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define sz(a) a.size()

typedef long long ll;
typedef pair < int, int > pii;
const int DL = 910;
const int LEN = 100100;
const int INF = int(1E9);
int x[110], y[110], dp[DL][DL];
bool use[DL][DL];
pair <int, int> dots[200010];
int main()
{
    //freopen("mantan.in", "r", stdin);
    //freopen("mantan.out", "w", stdout);
    int t, d, n, i, j, k, blx, bly, brx, bry, cnt = 1, cnt2;
    dots[0].x = 0;
    dots[0].y = 0;
    cin >> t >> d >> n;

    for (i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);

    for (i = 0; i < n; i++)
    {
        blx = x[i] - d - t;
        bly = y[i] - d - t;
        brx = x[i] + d + t;
        bry = y[i] + d + t;
        for (j = 0; j < DL; j++)
            for (k = 0; k < DL; k++)
                use[j][k] = 0;

        for (j = 0; j < cnt; j++)
            if ((dots[j].x >= blx) && (dots[j].x <= brx) && (dots[j].y >= bly) && (dots[j].x <= bry))
                use[dots[j].x - blx][dots[j].y - bly] = 1;
        for (j = 0; j < DL; j++)
            for (k = 0; k < DL; k++)
                {
                    dp[j][k] = INF;

                    if (use[j][k])
                        dp[j][k] = 0;

                    if (j - 1 >= 0)
                        dp[j][k] = min(dp[j - 1][k] + 1, dp[j][k]);
                }

        for (j = DL - 2; j >= 0; j--)
            for (k = 0; k < DL; k++)
                dp[j][k] = min(dp[j + 1][k] + 1, dp[j][k]);

        for (j = 0; j < DL; j++)
            for (k = 1; k < DL; k++)
                dp[j][k] = min(dp[j][k - 1] + 1, dp[j][k]);

        for (j = 0; j < DL; j++)
            for (k = DL - 2; k >= 0; k--)
                dp[j][k] = min(dp[j][k + 1] + 1, dp[j][k]);
        cnt2 = 0;
        //cout << "xy " << x[i] << ' ' << y[i] << endl;
        for (j = blx; j <= brx; j++)
            for (k = bly; k <= bry; k++)
                if ((dp[j - blx][k - bly] <= t) && (abs(j - x[i]) + abs(k - y[i]) <= d))
                    dots[cnt2++] = mp(j, k);
        cnt = cnt2;
    }
    //cout << d << endl;
    cout << cnt << endl;
    for (i = 0; i < cnt; i++)
        cout << dots[i].x << ' ' << dots[i].y << endl;
    /*for (j = blx; j <= brx; j++)
            for (k = bly; k <= bry; k++)
                cout << j << ' ' << k << ' ' << dp[j - blx][k - bly] << endl;
    cout << blx << ' ' << bly << endl;
    cout << brx << ' ' << bry << endl;*/
    return 0;
}


/*
2
2 20
2 10
3
10 5 5

2 1 5
0 1
-2 1
-2 3
0 3
2 5
*/
