#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[310][310];
int main()
{
    int n, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if ((i == j) || (n - j - 1 == i))
            {
                if ((a[i][j] != a[0][0]) || (a[i][j] == a[0][1]))
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            else
            {
                if ((a[i][j] != a[0][1]) || (a[i][j] == a[0][0]))
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    cout << "YES\n";
    return 0;
}
