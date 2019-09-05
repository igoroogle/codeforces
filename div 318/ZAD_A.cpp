#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010];
int main()
{
    int n, i;
    bool f = 1;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        while ((a[i] > 0) && (!(a[i] % 2)))
            a[i] /= 2;
        while ((a[i] > 0) && (!(a[i] % 3)))
            a[i] /= 3;
    }
    for (i = 1; i < n; i++)
        if (a[i] != a[i - 1])
        {
            f = 0;
            break;
        }
    if (f)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
