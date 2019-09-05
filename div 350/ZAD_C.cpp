#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
map <int, int> t;
int b[200010], c[200010];
int main()
{
    int n, i, x, y, nm = -1, m;
    pair<int, int> mn = mp(-1, -1);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        t[x]++;
    }

    cin >>  m;

    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < m; i++)
        scanf("%d", &c[i]);

    for (i = 0; i < m; i++)
    {
        x = t[b[i]];
        y = t[c[i]];
        if (mp(x, y) > mn)
        {
            mn = mp(x, y);
            nm = i + 1;
        }
    }

    cout << nm << endl;
    return 0;
}
