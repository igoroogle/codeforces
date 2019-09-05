#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define sz(n) n.size()

typedef long long ll;

int main()
{
    freopen("football.in", "r", stdin);
    freopen("football.out", "w", stdout);
    int n, i, j, p,  x, y, l, d;
    cin >> n;
    for (p = 0; p < n; p++)
    {
        scanf("%d:%d", &x, &y);
        l = 0;
        d = 0;
        for (i = 0; i <= 9; i++)
            for (j = 0; j <= 9; j++)
            {
                if (i + x > j + y)
                    l++;
                else if (i + x < j + y)
                    d++;
                else if (i > y)
                    l++;
                else if (i < y)
                    d++;
            }
        printf("%d %d\n", l, d);
    }
    return 0;
}
