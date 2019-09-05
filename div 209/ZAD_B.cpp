#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
int main()
{
    int n, k, i, vl = 0;
    cin >> n >> k;
    n *= 2;
    k *= 2;

    while (k > 0)
    {
        a[vl] = vl + 1;
        a[vl + 1] = vl + 2;
        a[vl + 2] = vl + 4;
        a[vl + 3] = vl + 3;
        vl += 4;
        k -= 2;
    }

    for (i = vl; i < n; i++)
        a[i] = i + 1;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
