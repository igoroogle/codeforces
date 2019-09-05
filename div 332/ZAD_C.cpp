#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
map <int, int> fr, sc;
int main()
{
    int n, i, ff = 0, ss = 0, ans = 0;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b, b + n);
    for (i = 0; i < n; i++)
    {
        if (sc[a[i]] == 0)
            {
                ff++;
                fr[a[i]]++;
            }
        else
        {
            ss--;
            sc[a[i]]--;
        }

        if (fr[b[i]] == 0)
            {
                ss++;
                sc[b[i]]++;
            }
        else
        {
            ff--;
            fr[b[i]]--;
        }

        if (ff + ss == 0)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
