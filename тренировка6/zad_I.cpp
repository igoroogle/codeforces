#include <bits/stdc++.h>
using namespace std;

//#define forn(i, n) for (int i = 0; i < n; i++)
//#define mp make_pair
//#define pb push_back
//#define sz(n) n.size()
//#define x first
//#define y second
typedef long long ll;
int a[5010], n;
bool prov(int k)
{
    int l = 0, r = 0, i;
    for(;;)
    {
        for (i = 0; i < k; i++)
        {
            r++;
            if (r >= n)
                return 1;
            if (a[l] < a[r])
                return 0;
        }
        l++;
    }
}
int main()
{
    freopen("viruses.in", "r", stdin);
    freopen("viruses.out", "w", stdout);
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; i++)
        if (prov(i))
        {
            cout << i << endl;
            return 0;
        }

    cout << 0 << endl;
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



