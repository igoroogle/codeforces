#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
char s[100010], ss[33];
int main()
{
    int n, m, i, j, ans = 0;
    bool f;
    scanf("%s%s", &s, &ss);
    n = strlen(s);
    m = strlen(ss);
    //cout << n << ' ' << m << endl;
    //cout << s << endl;
    //cout << ss << endl;
    i = 0;
    while (i < n - m + 1)
    {
        f = 0;
        for (j = 0; j < m; j++)
            if (s[i + j] != ss[j])
            {
                i++;
                f = 1;
                break;
            }

        if (f)
            continue;

        ans++;
        i += m;
    }

    cout << ans << endl;
    return 0;
}
