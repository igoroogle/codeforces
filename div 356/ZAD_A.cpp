#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[5];
int main()
{
    int n, i, j, k, sm = 0, mn;
    for (i = 0; i < 5; i++)
    {
        cin >> a[i];
        sm += a[i];
    }
    mn = sm;
    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 5; j++)
            if (a[i] == a[j])
                mn = min(mn, sm - a[i] - a[i]);

    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 5; j++)
            for (k = j + 1; k < 5; k++)
                if ((a[i] == a[j]) && (a[j] == a[k]))
                    mn = min(mn, sm - a[i] - a[i] - a[i]);

    cout << mn << endl;
    return 0;
}
