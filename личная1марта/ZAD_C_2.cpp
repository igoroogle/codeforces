#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int DL = 3010;
int a[20], n;
bool use[20][20];
int ans();//ii
int main()
{
    freopen("headmasters.in", "r", stdin);
    freopen("headmasters.out", "w", stdout);
    srand(time(0));
    int m, i, j, k, x, y, mn = INF, sm, smn;
    bool f;
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
        for (i = 0; i < n; i++)
        {
            a[i] = i;
            x = rand() % (i + 1);
            swap(a[i], a[x]);
        }
        sm = ans();
        f = 1;
        while (f)
        {
            f = 0;
            for (i = 0; i < n; i++)
                for (j = i + 1; i < n; i++)
                {
                    swap(a[i], a[j]);
                    smn = ans();
                    if (smn < sm)
                    {
                        sm = smn;
                        f = 1;
                        continue;
                    }

                    swap(a[i], a[j]);
                }
        }
        mn = min(mn, sm);
    }
    cout << mn << endl;
    return 0;
}
int ans()
{
    int sm = 0, i, j;
    for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (use[i][j])
                    sm += abs(a[i] - a[j]);
    return sm;
}
