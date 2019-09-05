#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 5013;
ld v[DL], p[DL], an[DL];
int a[2010];
int main()
{
    int n, i, j;
    ld ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i != j)
            {
                if (a[i] > a[j])
                    v[a[i] - a[j]] += ld(1) / (ld(ld(n) * ld(n - 1) / ld(2)));
            }

    for (i = DL - 2; i >= 0; i--)
        an[i] = an[i + 1] + v[i];
    for (i = 0; i < DL - 5; i++)
        for (j = 0; j < DL - 5; j++)
            if (i + j < DL - 5)
                ans += an[i + j + 1] * v[i] * v[j];
    cout << fixed << setprecision(11) << ans << endl;
    return 0;
}
