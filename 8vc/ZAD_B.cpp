#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef short int shi;
string s;
int dp[3][202][202][202];
int rec(int p, int i, int j, int k);
int main()
{
    int ans = 0, n, i, j, x = 0, y = 0, z = 0;
    cin >> n >> s;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            x++;
        if (s[i] == 'G')
            y++;
        if (s[i] == 'R')
            z++;
    }

    if (((x > 0) && (y > 0) && (z > 0)) || ((x > 1) && (y > 1)) || (((x > 1) && (z > 1))) || ((y > 1) && (z > 1)))
    {
        cout << "BGR\n";
        return 0;
    }

    if (rec(0, x, y, z) == 1)
        cout << 'B';
    if (rec(1, x, y, z) == 1)
        cout << 'G';
    if (rec(2, x, y, z) == 1)
        cout << 'R';
    cout << endl;
    return 0;
}

int rec(int p, int i, int j, int k)
{
    if (dp[p][i][j][k] != 0)
        return dp[p][i][j][k];
    if (i + j + k == 1)
    {
        if (((i == 1) && (p == 0)) || ((j == 1) && (p == 1)) || ((k == 1) && (p == 2)))
            dp[p][i][j][k] = 1;
        else
            dp[p][i][j][k] = 2;
        return dp[p][i][j][k];
    }
    bool f = 0;
    if ((i > 1) && (rec(p, i - 1, j, k) == 1))
        f = 1;
    if ((j > 1) && (rec(p, i, j - 1, k) == 1))
        f = 1;
    if ((k > 1) && (rec(p, i, j, k - 1) == 1))
        f = 1;
    if ((i > 0) && (j > 0) && (rec(p, i - 1, j - 1, k + 1) == 1))
        f = 1;
    if ((i > 0) && (k > 0) && (rec(p, i - 1, j + 1, k - 1) == 1))
        f = 1;
    if ((j > 0) && (k > 0) && (rec(p, i + 1, j - 1, k - 1) == 1))
        f = 1;
    if (f)
        dp[p][i][j][k] = 1;
    else
        dp[p][i][j][k] = 2;
    return dp[p][i][j][k];
}
