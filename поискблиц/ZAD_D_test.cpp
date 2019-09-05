#include <bits/stdc++.h>
using namespace std;
bool d[10];
int main()
{
    int n, i, j, kl, ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= 9; j++)
            d[j] = 0;
        j = i;

        while (j > 0)
        {
            d[j % 10]++;
            j /= 10;
        }

        kl = 0;
        for (j = 0; j < 10; j++)
            if (d[j] > 0)
                kl++;
        if (kl < 3)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
