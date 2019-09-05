#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[2010], b[300010];
vector<int> ans1, ans2;
int main()
{
    int n, i, j, sm;
    bool f;
    cin >> n;
    n *= 2;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++)
    {
        sm = a[0] + a[i];
        for (j = 0; j < n; j++)
            b[a[j]] = 0;
        for (j = 0; j < n; j++)
            b[a[j]]++;
        ans1.clear();
        ans2.clear();
        f = 0;
        for (j = 0; j < n; j++)
            if (b[a[j]] > 0)
            {
                ans1.pb(a[j]);
                ans2.pb(sm - a[j]);
                if (sm - a[j] < 0)
                {
                    f = 1;
                    break;
                }

                b[a[j]]--;
                b[sm - a[j]]--;
                if ((b[a[j]] < 0) || (b[sm - a[j]] < 0))
                {
                    f = 1;
                    break;
                }

            }

        if (f)
            continue;

        if ((ans1.size() == ans2.size()) && (ans1.size() + ans2.size() == n))
            break;
    }

    for (i = 0; i < ans1.size(); i++)
        printf("%d %d\n", ans1[i], ans2[i]);
    return 0;
}
