#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
int a[503][503];
bool use[1000100];
int main()
{
    int n, k, ans, i, j, viv = 0;
    cin >> n >> k;
    ans = n * n;
    k--;
    for (i = 0; i < n; i++)
        for (j = n - 1; j >= k; j--)
            {
                a[i][j] = ans--;
                use[a[i][j]] = 1;
            }

    ans = 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < k; j++)
        {
            while(use[ans])
                ans++;
            use[ans] = 1;
            a[i][j] = ans;
        }
    for (i = 0; i < n; i++)
        viv += a[i][k];
    cout << viv << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
            printf("%d ", a[i][j]);

        printf("%d\n", a[i][n - 1]);
    }
    return 0;
}
