#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
const int DL = 1004;
bool b[DL][DL];
int d1[DL][DL], d2[DL][DL];
int main()
{
    int n, i, j, x, y;
    ll ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        b[x][y] = 1;
    }

    for (i = 1; i < DL - 1; i++)
        for (j = 1; j < DL - 1; j++)
        {
            d1[i][j] = d1[i - 1][j - 1];
            if (b[i][j])
                d1[i][j]++;
            if ((d1[i][j] > 1) && (b[i][j]))
               ans += ll(d1[i][j] - 1);
            d2[i][j] = d2[i - 1][j + 1];
            if (b[i][j])
                d2[i][j]++;
            if ((d2[i][j] > 1) && (b[i][j]))
               ans += ll(d2[i][j] - 1);
        }

    cout << ans << endl;
}
