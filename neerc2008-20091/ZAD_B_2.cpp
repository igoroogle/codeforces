#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, bx[81], by[81], val[9], sum = 0;
bool a[9][9], use[9];
void rec(int nap);
int main()
{
    freopen("circuit.in", "r", stdin);
    freopen("circuit.out", "w", stdout);
    int i, j, x, y;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        a[x][y] = 1;
        a[y][x] = 1;
        bx[i] = x;
        by[i] = y;
    }
    rec(0);
    cout << sum << endl;
    return 0;
}
void rec(int nap)
{
    if (nap >= n)
    {
        for (int i = 0; i < m; i++)
            if (!(a[val[bx[i]]][val[by[i]]]))
                return;
        sum++;
        return;
    }
    for (int i = 0; i < n; i++)
        if (!use[i])
        {
            use[i] = 1;
            val[nap] = i;
            rec(nap + 1);
            use[i] = 0;
        }
}
