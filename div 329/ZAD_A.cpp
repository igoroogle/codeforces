#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ar[27];
ll b[27][27];
string s;
int main()
{
    ll i, j, k, n, m, f, l, mx = 0, ss;
    bool fl;
    cin >> n;
    for (i = 0; i < n; i++)
        {
            cin >> s;
            f = -1;
            l = -1;
            m = s.length();
            fl = 0;
            for (j = 0; j < m; j++)
                if (!ar[int(s[j] - 'a')])
                {
                    ar[int(s[j] - 'a')] = 1;
                    if ((f != -1) && (l != -1))
                    {
                        fl = 1;
                        break;
                    }

                    if (f == -1)
                        f = int(s[j] - 'a');
                    else
                        l = int(s[j] - 'a');
                }
            for (j = 0; j < 26; j++)
                ar[j] = 0;

            if ((f == -1) || (fl))
                continue;

            if (l == -1)
                b[f][f] += m;
            else
            {
                b[f][l] += m;
                b[l][f] += m;
            }
        }

    for (i = 0; i < 26; i++)
        for (j = 0; j < 26; j++)
        {
            if (i == j)
                ss = b[i][i];
            else
            {
                ss = b[i][j];
                ss += b[i][i];
                ss += b[j][j];
            }

            mx = max(ss, mx);
        }

    cout << mx << endl;
    return 0;
}
