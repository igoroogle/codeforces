#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool d1[12][12], d2[12][12], up[12][12], lf[12][12], use[12][12];
int n, k, ans = 0;

bool prov(int x, int y);
bool horse(int x, int y);
void rec(int x, int y, int val);

int main()
{
    //freopen("maharaja.in", "r", stdin);
    freopen("maharaja9.out", "w", stdout);
    cin >> n >> k;
    /*if (n > 11)
        for(;;);
    if (n == 10 && k > 5)
    {
        if (k == 6)
            cout << "541324";
        if (k == 7)
            cout << "188440";
        if (k == 8)
            cout << "20084";
        if (k == 9)
            cout << "488";
        if (k == 10)
            cout << "4";

    }
    else if (n == 11 && k > 3)
    {
        if (k == 4)
            cout << "712248";
        if (k == 5)
            cout << "2756122";
        if (k == 6)
            cout << "4878516";
        if (k == 7)
            cout << "3732024";
        if (k == 8)
            cout << "1131700";
        if (k == 9)
            cout << "119932";
        if (k == 10)
            cout << "3812";
        if (k == 11)
            cout << "44";
    }
    else if (n == 12 && k > 3)
    {
        if (k == 4)
            cout << "1882132";
        if (k == 5)
            cout << "10771928";
        if (k == 6)
            cout << "30868728";
        if (k == 7)
            cout << "74082028";
        if (k == 8)
            cout << "27250144";
        if (k == 9)
            cout << "7313248";
        if (k == 10)
            cout << "736460";
        if (k == 11)
            cout << "23272";
        if (k == 12)
            cout << "0";

    }
    else*/
    {
        rec(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}

bool prov(int x, int y)
{
    if ((x < 0) || (y < 0) || (x >= n)|| (y >= n))
        return 0;
    return use[x][y];
}

bool horse(int x, int y)
{
    if (prov(x - 2, y - 1))
        return 1;
    if (prov(x - 2, y + 1))
        return 1;
    if (prov(x - 1, y - 2))
        return 1;
    if (prov(x - 1, y + 2))
        return 1;
    return 0;
}

void rec(int x, int y, int val)
{
    if (x >= n)
        return;
    d1[x][y] = 0;
    d2[x][y] = 0;
    lf[x][y] = 0;
    up[x][y] = 0;
    use[x][y] = 0;
    int xt, yt;
    xt = x;
    yt = y;
    if (y + 1 < n)
        yt++;
    else
    {
        xt++;
        yt = 0;
    }
    if ((x - 1 >= 0) && (y - 1 >= 0))
        d1[x][y] = d1[x - 1][y - 1];

    if ((x - 1 >= 0) && (y + 1 < n))
        d2[x][y] = d2[x - 1][y + 1];
    if (x - 1 >= 0)
        lf[x][y] = lf[x - 1][y];
    if (y - 1 >= 0)
        up[x][y] = up[x][y - 1];
    use[x][y] = 0;
    rec(xt, yt, val);
    if (horse(x, y))
        return;
    if (d1[x][y])
        return;
    if (d2[x][y])
        return;
    if (lf[x][y])
        return;
    if (up[x][y])
        return;
    if (val + 1 == k)
    {
        ans++;
        return;
    }

    d1[x][y] = 1;
    d2[x][y] = 1;
    lf[x][y] = 1;
    up[x][y] = 1;
    use[x][y] = 1;
    rec(xt, yt, val + 1);
    d1[x][y] = 0;
    d2[x][y] = 0;
    lf[x][y] = 0;
    up[x][y] = 0;
    use[x][y] = 0;
}
