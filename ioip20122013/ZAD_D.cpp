#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll DL = 62;
int a[200010];
pair<int, int> b[200010];
map<int, int> t;
bool comp(pair<int, int> a, pair<int, int> b);
int x[200010], y[200010];
int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    int n, i, kl = 0;
    cin >> n;
    n <<= 1;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (i = 1; i < n; i++)
        b[i - 1] = mp(a[i - 1], a[i]);

    for (i = 0; i < n; i++)
        t[a[i]]++;

    n--;
    sort(b, b + n, comp);
    for (i = 0; i < n; i++)
    {
        if ((t[b[i].x] == 0) || (t[b[i].y] == 0))
            continue;
        kl++;
        x[kl - 1] = b[i].y;
        y[kl - 1] = b[i].x;
        t[b[i].x]--;
        t[b[i].y]--;
    }

    for (i = 0; i < kl - 1; i++)
        printf("%d ", x[i]);
    printf("%d\n", x[kl - 1]);

    for (i = 0; i < kl - 1; i++)
        printf("%d ", y[i]);
    printf("%d\n", y[kl - 1]);

    return 0;
}

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.y - a.x < b.y - b.x)
        return 1;

    if (a.y - a.x > b.y - b.x)
        return 0;

    return (a.x + a.y > b.x + b.y);
}
