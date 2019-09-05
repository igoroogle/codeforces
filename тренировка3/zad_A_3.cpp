#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int LEN = 200200, INF = 1000000;
int n, ar[LEN][2], dist[LEN], r, q[LEN * 2], minx, maxx, a;

int main()
{
    freopen("redblack.in", "r", stdin);
    freopen("redblack.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> ar[i][0] >> ar[i][1];
        ar[i][0]--;
        ar[i][1]--;
    }

    for (int i = 1; i < n; i++)
        dist[i] = INF;
    r = 1;

    for (int i = 0; i < r; i++)
    {
        a = q[i];
        if (a == n - 1)
            continue;

        if (dist[ar[a][0]] > dist[a] + 1)
        {
            dist[ar[a][0]] = dist[a] + 1;
            q[r] = ar[a][0];
            r++;
        }
        if (dist[ar[a][1]] > dist[a] + 1)
        {
            dist[ar[a][1]] = dist[a] + 1;
            q[r] = ar[a][1];
            r++;
        }
    }

    minx = dist[n - 1] - 1;

    for (int i = 0; i < n - 1; i++)
        if (ar[i][0] == n - 1 || ar[i][1] == n - 1)
            maxx = max(maxx, dist[i]);

    if (maxx / 2 >  minx)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}


