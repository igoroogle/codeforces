#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
const int INF = 2000000000;
string s, s1, s2;
int main()
{
    int n, i, j, z, p, ind, val1 = 0, val2 = 0, val3 = 0, z1, p1, z2, p2, ind0, vv = 0, vv2, ans = INF;
    bool f;
    cin >> n >> s;
    s2 = s;
    s1 = s;
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

    ind = p;
    while (ind >= z)
    {
        if (s[ind] != 'A')
        {
            for (i = ind + 1; i <= p; i++)
            {
                swap(s[i], s[i - 1]);
                vv++;
            }
            p--;
            ind--;
            vv2 = 0;
            ind0 = ind;
            s1 = s;
            z1 = z;
            p1 = p;
            while (ind0 >= z)
            {
                if (s1[ind0] == 'F')
                {
                    for (i = ind0 + 1; i < n; i++)
                    {
                        swap(s1[i], s1[i - 1]);
                        vv2++;
                    }
                    ind0--;
                    p--;
                }
                else ind0--;
            }
            z = z1;
            p = p1;
            ans = min(ans, vv + vv2);
        }
        else ind--;
    }
    ans = min(ans, vv);
    //===============
    s = s2;
    reverse(s.begin(), s.end());
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'F')
            s[i] = 'A';
        else if (s[i] == 'A')
            s[i] = 'F';
    }
    s1 = s;
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

    ind = p;
    while (ind >= z)
    {
         while (s[z + 1] == 'N')
        {
            val1++;
            swap(s[z], s[z + 1]);
            z++;
        }

        while (s[p - 1] == 'N')
        {
            val1++;
            swap(s[p], s[p - 1]);
            p--;
        }
        if (s[ind] != 'A')
        {
            for (i = ind + 1; i <= p; i++)
            {
                swap(s[i], s[i - 1]);
                vv++;
            }
            p--;
            ind--;
            vv2 = 0;
            ind0 = ind;
            s1 = s;
            z1 = z;
            p1 = p;
            while (ind0 >= z)
            {
                 while (s[z + 1] == 'N')
        {
            val1++;
            swap(s[z], s[z + 1]);
            z++;
        }

        while (s[p - 1] == 'N')
        {
            val1++;
            swap(s[p], s[p - 1]);
            p--;
        }
                if (s1[ind0] == 'F')
                {
                    for (i = ind0 + 1; i < n; i++)
                    {
                        swap(s1[i], s1[i - 1]);
                        vv2++;
                    }
                    ind0--;
                    p--;
                }
                else ind0--;
            }
            z = z1;
            p = p1;
            ans = min(ans, vv + vv2);
        }
        else ind--;
    }
    ans = min(ans, vv);
    cout << ans << endl;
    return 0;
}
