#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MX = 2000000001;
string s, ss = "1";
int main()
{
    ll n, ans = 1, k = 0,  x, m, i, j, f;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "0")
        {
            cout << 0 << endl;
            return 0;
        }

        m = s.length();
        f = 1;
        if (s[0] > '1')
        {
            f = 0;
            ss = s;
        }

        for (j = 1; j < m; j++)
            if (s[j] != '0')
            {
                f = 0;
                ss = s;
                break;
            }

        if (f)
            k += m - 1;
    }

    cout << ss;
    for (i = 0; i < k; i++)
        printf("0");
    cout << endl;
    return 0;
}
