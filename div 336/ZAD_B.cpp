#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll sum1[200010], sum2[200010];
string s1, s2;
int main()
{
    ll n, m, ans = 0, i;
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    sum1[0] = 0;
    sum2[0] = 0;

    for (i = 1; i <= m; i++)
    {
        sum1[i] = sum1[i - 1];
        sum2[i] = sum2[i - 1];
        if (s2[i - 1] == '0')
            sum1[i]++;
        else
            sum2[i]++;
    }
    if (n > m)
    {
        cout << 0 << endl;
        return 0;
    }

    for (i = 1; i <= n; i++)
    {
        if (s1[i - 1] == '1')
        {
            ans += sum1[m - n + i] - sum1[i - 1];
        }
        else
        {
            ans += sum2[m - n + i] - sum2[i - 1];
        }
    }

    cout << ans << endl;
    return 0;
}
