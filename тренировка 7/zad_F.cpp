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

const int N = 200000;

int n, n1, f;
pii a[N];
vector <pii> ans, ans1;

int main()
{
    freopen("smith.in", "r", stdin);
    freopen("smith.out", "w", stdout);

    cin >> n;
    forn(i, n)
    {
        scanf("%d", &a[i].x);
        a[i].y = i + 1;
    }
    sort(a, a + n);

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
            ans.push_back(a[i]);
    for (int i = n - 1; i >= 0; i--)
        if (a[i].x > 0)
            ans1.push_back(a[i]);

    if (ans.size() % 2)
        ans.pop_back();

    n1 = ans.size() + ans1.size();
    if (n1 == n)
    {
        if (ans.size() > 0 && ans1.size() > 0)
        {
            if (ans[ans.size() - 1].x * ans[ans.size() - 1].x < ans1[ans1.size() - 1].x)
            {
                ans.pop_back();
                ans.pop_back();
                f = 1;
            }
            else
                ans1.pop_back();
        }
        else if (ans.size() > 0)
        {
            ans.pop_back();
            ans.pop_back();
        }
        else if (ans1.size() > 0)
            ans1.pop_back();
    }

    n1 = ans.size() + ans1.size();

    if (n1 == 0 || n1 == n)
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
