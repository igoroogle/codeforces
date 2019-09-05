#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
string s;
int main()
{
    int ans = 0, n, i, j, x, y;
    cin >> n >> s;
    for (i = 0; i < n; i++)
    {
        x = 0;
        y = 0;
        for (j = i; j < n; j++)
        {
            if (s[j] == 'U')
                x++;
            else if (s[j] == 'D')
                x--;
            else if (s[j] == 'L')
                y--;
            if (s[j] == 'R')
                y++;
            if ((x == 0) && (y == 0))
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
