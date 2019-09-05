#include <bits/stdc++.h>
#define mp mak_pair
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    int n, h, i, ans = 0, x;
    cin >> n >> h;
    while (n--)
    {
        scanf("%d", &x);
        if (x <= h)
            ans++;
        else
            ans += 2;
    }

    cout << ans << endl;
    return 0;
}
