#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(a) ((a) * (a))
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 457839487523;
const ll P = 768477;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const int N = 300001;
const int M = 12001;
ll a[100010], b[100010], c[100010];
int main()
{
    freopen("story.in", "r", stdin);
    freopen("story.out", "w", stdout);
    ll n, m, s, r, i, j, cnt = 0, sm = 0;
    cin >> n >> m >> s >> r;
    if ((n * (n - 1) / 2 < m) || (m < n - 1) || (n - 1 > s) || ((n - 1) * r < s))
    {
        cout << -1 << endl;
        return 0;
    }

    for (i = 1; i < n; i++)
    {
        cnt++;
        a[cnt - 1] = i;
        b[cnt - 1] = i + 1;
        c[cnt - 1] = 1;
        sm++;
    }
    for (i = 0; i < cnt; i++)
    {
        if (sm == s)
            break;
        if (s - sm <= r - 1)
        {
            c[i] = c[i] + s - sm;
            sm = s;
            break;
        }
        sm += r - 1;
        c[i] = r;
    }
    for (i = 1; i <= n; i++)
    {
        if (cnt == m)
            break;
        for (j = i + 2; i <= n; j++)
        {
            if (cnt == m)
                break;
            if (cnt < m)
            {
                cnt++;
                a[cnt - 1] = i;
                b[cnt - 1] = j;
                c[cnt - 1] = r;
            }
        }
    }

    for (i = 0; i < m; i++)
        printf("%d %d %d\n", int(a[i]), int(b[i]), int(c[i]));
    return 0;
}





