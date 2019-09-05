#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int DL = 100010;
int a[20];
bool use[20][20];
int main()
{
    freopen("headmasters.in", "r", stdin);
    freopen("headmasters.out", "w", stdout);
    srand(time(NULL));
    int n, m, i, j, k, x, y, mn = INF, sm;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        if (x > y)
            swap(x, y);
        use[x][y] = 1;
    }

    for (k = 0; k < DL; k++)
    {
        sm = 0;
        for (i = 0; i < n; i++)
        {
            a[i] = i;
            x = rand() % (i + 1);
            swap(a[i], a[x]);
        }
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (use[a[i]][a[j]])
                    sm += j - i;
        mn = min(mn, sm);
    }
    cout << mn << endl;
    return 0;
}
