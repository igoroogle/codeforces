#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 100000000000;
string s;
int main()
{
    ll n, m, ans = 0, i, x;
    char c;
    cin >> n >> m >> s;
    for (i = 1; i < n; i++)
        if ((s[i] == '.') && (s[i - 1] == '.')) ans++;
    for (i = 0; i < m; i++)
    {
        scanf("%I64d", &x);
        x--;
        cin >> c;
        if (((c == '.') && (s[x] == '.')) || ((c != '.') && (s[x] != '.')))
        {
            printf("%I64d\n", ans);
            continue;
        }

        if (s[x] == '.')
        {
            if ((x - 1 >= 0) && (s[x - 1] == '.')) ans--;
            if ((x + 1 < n) && (s[x + 1] == '.')) ans--;
            s[x] = c;
            printf("%I64d\n", ans);
            continue;
        }
        if ((x - 1 >= 0) && (s[x - 1] == '.')) ans++;
        if ((x + 1 < n) && (s[x + 1] == '.')) ans++;
        s[x] = c;
        printf("%I64d\n", ans);
    }
    return 0;
}
