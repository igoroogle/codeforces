#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 2000000010;
int v[4010], d[4010], p[4010], ans[4010];
int main()
{
    int n, i, j, t, kol = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d%d%d", &v[i], &d[i], &p[i]);
    for (i = 0; i < n; i++)
    {
        if (p[i] < 0)
        {
            for (j = i + 1; j < n; j++)
                p[j] = max(-1, p[j] - d[i]);
        }
        else
        {
            ans[kol++] = i + 1;
            t = v[i];
            for (j = i + 1; j < n; j++)
                if (p[j] >= 0)
                {
                    p[j] = max(-1, p[j] - t);
                    t = max(0, t - 1);
                }
        }

    }

    cout << kol << endl;
    for (i = 0; i < kol; i++)
        printf("%d ", ans[i]);
    return 0;
}
