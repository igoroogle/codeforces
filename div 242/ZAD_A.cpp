#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string s;
int main()
{
    ll n, up = 0, down = 0, ans = 0, i;
    cin >> n >> s;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'X') up++;
        else down++;
    }
    while (up != down)
    {
        ans++;
        if (up > down )
        {
            for (i = 0; i < n; i++)
                if (s[i] == 'X')
                {
                    s[i] = 'x';
                    up--;
                    down++;
                    break;
                }
        }
        else
        {
                for (i = 0; i < n; i++)
                if (s[i] == 'x')
                {
                    s[i] = 'X';
                    down--;
                    up++;
                    break;
                }
        }
    }
    cout << ans << endl;
    cout << s << endl;
    return 0;
}
