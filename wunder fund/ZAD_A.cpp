#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int ans[100010];
int main()
{
    int k, n, i, kl = 1;
    cin >> n;
    ans[0] = 1;
    for (i = 1; i < n; i++)
    {
        ans[kl++] = 1;
        while ((kl > 1) && (ans[kl - 1] == ans[kl - 2]))
        {
            kl--;
            ans[kl - 1]++;
        }
    }

    for (i = 0; i < kl; i++)
        printf("%d ", ans[i]);

    return 0;
}
