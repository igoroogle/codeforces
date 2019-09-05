#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int LEN = 100100, INF = 1000000000;
int n, t, m, ar[LEN], a, b, c, w, cnt[LEN], kol, v, dist[LEN], q[LEN * 2], r;
vector <int> ed[LEN];

int main()
{
    freopen("war.in", "r", stdin);
    freopen("war.out", "w", stdout);

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        ed[a - 1].push_back(b - 1);
        ed[b - 1].push_back(a - 1);
    }


    cin >> c >> w;
    c--;

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[c] = 0;

    q[0] = c;
    r = 1;
    for (int i = 0; i < r; i++)
    {
        a = q[i];

        for (int j = 0; j < ed[a].size(); j++)
            if (dist[a] + 1 < dist[ed[a][j]])
            {
                q[r] = ed[a][j];
                dist[ed[a][j]] = dist[a] + 1;
                r++;
            }
    }

    for (int i = 0; i < n; i++)
        if (dist[i] < INF)
            cnt[dist[i]] += ar[i];

    for (int i = 0; i < LEN; i++)
    {
        kol += cnt[i];

        v = min(t, min(kol, w));
        kol -= v;
        w -= v;

        if (kol == 0 && w > 0)
        {
            cout << "Werewolves win";
            return 0;
        }
    }

    cout << "Vampires win";

    return 0;
}

