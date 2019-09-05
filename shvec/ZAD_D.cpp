#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1003];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, i, j;
    cin >> n;
    cout << (n - 1) / 2 + 1 << endl;
    m = n - n % 2;
    for (i = 0; i < m; i++)
        a[i] = i + 1;
    for (i = 0; i < m / 2; i++)
    {
        printf("%d ", m / 2);
        for (j = 0; j < m / 2; j++)
            printf("%d ", a[j]);
        printf("\n");
        a[m + 1] = a[1];
        for (j = 1; j < m; j++)
            a[j] = a[j + 1];
    }
    if (m < n)
        cout << 1 << ' ' << n << endl;
    return 0;
}
