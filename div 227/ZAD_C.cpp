#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
    int i, j, n, ans = 0, f = 0, len = 0, len2 = 0, ost = 0;
    char c;
    cin >> s;
    n = s.length();
    i = n - 1;
    while (i >= 0)
    {
        if (f == 0)
        {
            if (i - 1 < 0)
            {
                ost = 1;
                break;
            }
            if ((s[i - 1] >= s[i]) && (s[i] != '0') && (s[i - 1] != '0'))
            {
                ans += 2;
                i -= 2;
                ost = 0;
                continue;
            }
            if (s[i] == '0')
            {
                f = 1;
                len = 1;
                i--;
                ost = 1;
                continue;
            }
            len = 1;
            len2 = 1;
            c = s[i];
            i-=2;
            ost = 1;
            f = 2;
            continue;
        }
        else if (f == 1)
        {
            len++;
            if (s[i] == '0')
            {
                i--;
                ost = 1;
                continue;
            }
            f = 2;
            c = s[i];
            i--;
            ost = 1;
            len2 = 0;
            continue;
        }
        else if (f == 2)
        {
            len2++;
            if ((s[i] != '0') && (((len2 >= len) && (s[i] >= c)) || (len2 > len)))
            {
                f = 0;
                ans += 2;
                ost = 0;
                i--;
                continue;
            }
            ost = 1;
            i--;
            continue;
        }
    }
    cout << ans + ost << endl;
    return 0;
}
