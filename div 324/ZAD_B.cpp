#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
string s1, s2;
char s3[100010];
int main()
{
    int n, t, raz = 0, odin = 0, i, kol = 0;
    cin >> n >> t >> s1 >> s2;
    for (i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            odin++;
        else
            raz++;
    }

    if (raz % 2)
    {
        cout << -1 << endl;
        return 0;
    }

    if (raz / 2 > t)
    {
        cout << -1 << endl;
        return 0;
    }

    if (raz / 2 + odin < t)
    {
        cout << -1 << endl;
        return 0;
    }
    kol = t - raz / 2;
    for (i = 0; i < n; i++)
    {
        if ((s1[i] == s2[i]) && (kol > 0))
            {
                kol--;
                if (s1[i] != 'a')
                    s3[i] = 'a';
                else
                    s3[i] = 'b';
            }
        if (s1[i] != s2[i])
        {
            if (raz % 2)
                s3[i] = s1[i];
            else
                s3[i] = s2[i];
            raz--;
        }
    }
    for (i = 0; i < n; i++)
        printf("%c", s3[i]);
    return 0;
}
