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

int n;
pii a[N];


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
    int k = 0;
    forn(i, n)
    {
        if (a[i].x >= 0)
            break;
        k++;
    }
    if (k & 1)
    {
        cout << n - k << endl;
        for (int i = k; i < n; i++)
            cout << a[i].y << ' ';

    }
    else
    {
        cout << n << endl;
        forn(i, n)
            cout << i + 1 << ' ';
    }


    return 0;
}
