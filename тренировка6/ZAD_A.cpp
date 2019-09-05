#include <bits/stdc++.h>
using namespace std;

//#define forn(i, n) for (int i = 0; i < n; i++)
//#define mp make_pair
//#define pb push_back
//#define sz(n) n.size()
//#define x first
//#define y second

typedef long long ll;

struct point
{
    ll x, y;
};

void cin_p(point &a)
{
    cin >> a.x >> a.y;
}

const int LEN = 100100;
int n;
point p, ar[LEN];
ll sum, x, y, x1, y1, sum1, s, ind;

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin_p(ar[i]);
    cin_p(p);

    ar[n] = ar[0];
    sum1 = 99999999999999999;

    for (int i = 0; i < n; i++)
    {
        x = ar[i].x - p.x;
        y = ar[i].y - p.y;
        x1 = ar[i + 1].x - p.x;
        y1 = ar[i + 1].y - p.y;

        if (sum1 > abs(x * y1 - x1 * y))
        {
            sum1 = abs(x * y1 - x1 * y);
            ind = i;
        }
    }

    cout << n + 1 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ar[i].x << " " << ar[i].y << endl;
        if (i == ind)
            cout << p.x << " " << p.y << endl;
    }


    return 0;
}

/*

5
3 3 2 5 1
1 2
2 3
2 4
4 5


*/



