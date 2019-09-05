#include<bits/stdc++.h>
using namespace std;
char s[10010];
int main()
{
    int n, d, i, kl = 0, ans = 0;
    bool f;
    cin >> d >> n;
    while (n--)
    {
        scanf("%s", &s);
        f = 0;
        for (i = 0; i < d; i++)
            if (s[i] == '0')
            {
                f = 1;
                break;
            }

        if (f)
            kl++;
        else
            kl = 0;
        ans = max(kl, ans);
    }

    cout << ans << endl;
    return 0;
}
