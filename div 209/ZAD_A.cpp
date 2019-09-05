#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    int n, m, i, j, x;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            scanf("%d", &x);
            if ((x) && ((j == 0) || (j == m - 1) || (i == 0) || (i == n - 1)))
            {
                cout << 2 << endl;
                return 0;
            }
        }
    cout << 4 << endl;
    return 0;
}
