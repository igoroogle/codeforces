#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
string s1, s2;
char s3[100010];
int main()
{
    int n, t, raz = 0, odin = 0, i, kol = 0, other = 0, chered = 0, val = 0, ans = 0;
    cin >> n >> t >> s1 >> s2;
    for (i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            odin++;
        else
            raz++;
    }

    if ((raz > 0) && ((raz - 1) / 2 + 1 > t))
    {
        cout << -1 << endl;
        return 0;
    }

    if (raz + odin < t)
    {
        cout << -1 << endl;
        return 0;
    }
    ans = raz - (raz % 2);
    val = ans / 2 + raz - ans;
    while ((raz > t) && (val  < t))
    {
        ans -= 2;
        val = ans / 2 + raz - ans;
    }

    if ((raz > t) && (val > t))
    {
        ans += 2;
        val = ans / 2 + raz - ans;
        if (odin == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        kol++;
    }

    if (raz > t)
    {
        chered = ans;
        other = raz - ans;
    }
    else
    {
        chered = 0;
        other = raz;
        kol = t - raz;
    }

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
        else if (s1[i] == s2[i])
            s3[i] = s1[i];
        if ((s1[i] != s2[i]) && (other > 0))
        {
            if ((s1[i] != 'a') && (s2[i] != 'a'))
                s3[i] = 'a';
            else if ((s1[i] != 'b') && (s2[i] != 'b'))
                s3[i] = 'b';
            else
                s3[i] = 'c';
            other--;
        }
        else if ((s1[i] != s2[i]) && (chered > 0))
        {
            if (chered % 2)
                s3[i] = s1[i];
            else
                s3[i] = s2[i];
            chered--;

        }
    }
    for (i = 0; i < n; i++)
        printf("%c", s3[i]);
    return 0;
}
