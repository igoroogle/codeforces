#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
vector<int> ans;
int a[100010];
int main()
{
    int n, m, i, cr = 1;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);
    a[n++] = 1000000001;

    for (i = 0; i < n; i++)
    {
        if (m < cr)
            break;
        while ((cr < a[i]) && (m >= cr))
        {
            ans.pb(cr);
            m -= cr;
            cr++;
        }

        cr = max(cr, a[i] + 1);
    }

    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}
