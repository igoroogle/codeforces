#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
const int INF = 2000000000;
string s;
int main()
{
    int n, i, j, z, p, zs, ps, ans = 0;
    bool f;
    cin >> n >> s;
    for (i = 0; i < n; i++)
        if (s[i] == 'F')
        {
            z = i;
            break;
        }

    for (i = n - 1; i >= 0; i--)
        if (s[i] == 'A')
        {
            p = i;
            break;
        }

    while (z < p)
    {
        while ((z < p) && (s[z + 1] != s[z]))
        {
            ans++;
            swap(s[z], s[z + 1]);
            z++;
        }

        for (i = 0; i < n; i++)
            if (s[i] == 'F')
            {
                z = i;
                break;
            }

        for (i = n - 1; i >= 0; i--)
            if (s[i] == 'A')
            {
                p = i;
                break;
            }

        while ((z < p) && (s[p - 1] != s[p]))
        {
            ans++;
            swap(s[p], s[p - 1]);
            p--;
        }

        for (i = 0; i < n; i++)
            if (s[i] == 'F')
            {
                z = i;
                break;
            }

        for (i = n - 1; i >= 0; i--)
            if (s[i] == 'A')
            {
                p = i;
                break;
            }

    }
    ans += z - p - 1;
    cout << ans << endl;
    return 0;
}
