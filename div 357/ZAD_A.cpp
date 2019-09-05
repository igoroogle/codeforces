#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
char s[100010];
int main()
{
    int n, x, y, i;
    cin >> n;
    while (n--)
    {
        scanf("%s%d%d", &s, &x, &y);
        if ((y > x) && (x >= 2400))
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
