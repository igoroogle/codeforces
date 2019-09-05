#include <bits/stdc++.h>
using namespace std;

const int LEN = 1000100;
int n, ar[LEN], dp[LEN], dp1[LEN], j, n1, f;
char ch;

int main()
{
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);

    while (f || cin >> ch)
        if (ch == '^')
        {
            n++;

            f = 0;

            while (true)
            {
                scanf("%c", &ch);
                if (ch >= '0' && ch <= '9')
                {
                    ar[n] = ar[n] * 10 + int(ch - '0');

                    if (ar[n] > 1000000)
                        break;
                }
                else
                {
                    if (ch == '^')
                        f = 1;
                    break;
                }
            }
        }

    j = 1;
    for (int i = 1; i <= n; i++)
    {
        if (ar[i] == j)
            j++;
        dp[i] = j - 1;
    }

    j--;
    n1 = j;

    for (int i = n; i >= 0; i--)
    {
        if (ar[i] == j)
            j--;
        dp1[i] = j + 1;
    }

    cout << n << endl;
    for (int i = 1; i <= n; i++)
        if (i == 1 && dp1[i + 1] == 1)
            cout << "Y";
        else if (i == n && dp[i - 1] == n1)
            cout << "Y";
        else if (i != 1 && i != n && dp[i - 1] + 1 >= dp1[i + 1])
            cout << "Y";
        else
            cout << "N";
    cout << endl;

    for (int i = 1; i <= n; i++)
        if (i == 1 && ar[i] == 1)
            cout << "Y";
        else if (i == n && ar[i] == n1)
            cout << "Y";
        else if (i != n && i != 1 && dp[i - 1] >= ar[i] - 1 && dp1[i + 1] <= ar[i] + 1)
            cout << "Y";
        else
            cout << "N";

    return 0;
}

/*
sample: 2 plus 2 equals 2^2. ^1 easy, ^2 isnt it? 1^1 equals 1.
*/
