#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[2][200][200][200];
int rec(int t, int k, int i, int j);
int main()
{
    int t, k, i, j;
    for (t = 0; t < 2; t++)
        for (k = 0; k < 200; k++)
            for (i = 0; i < 200; i++)
                for (j = 0; j < 200; j++)
                    dp[t][k][i][j] = -1;
    return 0;
}

int rec(int k, int i, int j)
{
    if (dp[t][k][i][j] != -1)
        return dp[t][k][i][j];
    if (i + j == k)
    {
        if ((i + j) % 2 != t)
            dp[t][k][i][j]
    }
    if (t == 0)
    {
        if ((i > 1) && ()
    }
}
