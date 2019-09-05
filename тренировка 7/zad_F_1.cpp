#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define x first
#define y second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int N = 200000, MOD = 1000000007;

int n, n1, f, use[N], p, p1;
pii a[N];
vector <pii> ans, ans1;

int main()
{
    freopen("smith.in", "r", stdin);
    +++++++++++++++++++freopen("smith.out", "w", stdout);

    cin >> n;
    forn(i, n)
    {
        scanf("%d", &a[i].x);
        a[i].y = i + 1;
    }
    sort(a, a + n);

    if (n == 2)
    {
        p = max(a[0].x, a[1].x);
        p1 = min(a[0].x, a[1].x);

        if (p == p1)
            cout << "Impossible";
        else
        {
            cout << 1 << endl;
            if (a[0].x > a[1].x)
                cout << a[0].y;
            else
                cout << a[1].y;
        }
        return 0;
    }

    for (f = 1; f < n; f++)
        if (a[f].x != a[f - 1].x)
            break;

    if (f == n && (n <= 2 || a[0].x == 1 || (n % 2 == 0 && a[0].x == -1)))
    {
        cout << "Impossible";
        return 0;
    }

    for (int i = 0; i < n; i++)
        if (a[i].x < 0)
        {
            ans.push_back(a[i]);
            use[a[i].y] = 1;
        }
    for (int i = n - 1; i >= 0; i--)
        if (a[i].x > 0)
        {
            ans1.push_back(a[i]);
            use[a[i].y] = 1;
        }

    if (ans.size() % 2)
    {
        use[ans[ans.size() - 1].y] = 0;
        ans.pop_back();
    }
    n1 = ans.size() + ans1.size();
    if (n1 == n)
    {
        if (ans.size() > 0 && ans1.size() > 0)
        {
            if (ans[ans.size() - 1].x * ans[ans.size() - 1].x < ans1[ans1.size() - 1].x)
            {
                use[ans[ans.size() - 1].y] = use[ans[ans.size() - 2].y] = 0;
                ans.pop_back();
                ans.pop_back();
                f = 1;
            }
            else
            {
                use[ans1[ans1.size() - 1].y] = 0;
                ans1.pop_back();
            }
        }
        else if (ans.size() > 0)
        {
            use[ans[ans.size() - 1].y] = use[ans[ans.size() - 2].y] = 0;
            ans.pop_back();
            ans.pop_back();
        }
        else if (ans1.size() > 0)
        {
            use[ans1[ans1.size() - 1].y] = 0;
            ans1.pop_back();
        }
    }

    n1 = ans.size() + ans1.size();

    for (int i = 0; i < n; i++)
        use[i] = 0;
    for (int i = 0; i < ans.size(); i++)
        use[ans[i].y];
    for (int i = 0; i < ans1.size(); i++)
        use[ans1[i].y];

    p = p1 = 1;
    for (int i = 0; i < n; i++)
        if (use[i])
            p = (p * a[i].x) % MOD;
        else
            p1 = (p1 * a[i].x) % MOD;

    if (n1 == 0 || n1 == n || p == p1)
    {
        cout << "Impossible";
        return 0;
    }

    cout << ans.size() + ans1.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].y << " ";
    for (int i = 0; i < ans1.size(); i++)
        cout << ans1[i].y << " ";

    return 0;
}
