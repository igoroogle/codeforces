#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    //freopen("coloring.in", "r", stdin);
    //freopen("coloring.out", "w", stdout);
    int n, i, f = -1, l = -1, ff, ll;
    bool ans = 0;
    cin >> n >> s;
    for (i = 0; i < n; i++)
        if (s[i] != '0')
        {
            f = i;
            break;
        }

    for (i = n - 1; i >= 0; i--)
        if (s[i] != '0')
        {
            l = i;
            break;
        }
    if (f == -1)
    {
        if (n % 2)
            cout << "FIRST\n";
        else
            cout << "SECOND\n";
        return 0;
    }
    if (f > 0)
        ans ^= 1;
    if (l < n - 1)
        ans ^= 1;
    ff = f;
    l++;
    for (i = f + 1; i < l; i++)
        if (s[i] != '0')
        {
            ll = i;
            ans ^= ((ll - ff > 1) && ((s[ff] == s[ll]) || ((ll - ff) % 2)));
            ff = i;
        }

    if (ans)
            cout << "FIRST\n";
        else
            cout << "SECOND\n";
    return 0;
}
