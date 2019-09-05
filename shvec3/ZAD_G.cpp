#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, t;
int lef[200010], rig[200010], a[27];
int main()
{
    int n, m, i, j;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    if (n < m)
    {
        cout << "No\n";
        return 0;
    }

    j = 0;
    for (i = 0; i < n; i++)
    {
        if ((j < m) && (t[j] == s[i]))
            j++;
        lef[i] = j;
    }

    j = m - 1;
    for (i = n - 1; i >= 0; i--)
    {
        if ((j >= 0) && (t[j] == s[i]))
            j--;
        rig[i] = j;
    }
    for (i = 0; i < 26; i++)
        a[i] = -1;
    j = 0;
    a[int(t[j] - 'a')] = 0;
    for (i = 0; i < n; i++)
    {
        if ((a[int(s[i] - 'a')] == -1) || (a[int(s[i] - 'a')] < rig[i]))
        {
            cout << "No\n";
            return 0;
        }

        if ((j < m - 1) && (t[j] == s[i]))
        {
            j++;
            a[int(t[j] - 'a')] = j;
        }
    }
    cout << "Yes\n";
    return 0;
}
