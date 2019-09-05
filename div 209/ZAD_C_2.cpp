#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ull MOD = 1000000007;
ull a[200010], b[200010];
ull binst(ull x, ull n);
int main()
{
    ull n, m = 1, x, i, sm = 0, stp = 0, ost, pw;
    cin >> n >> x;
    for (i = 0; i < n; i++)
        {
            cin >> a[i];
            sm += a[i];
        }

    for (i = 0; i < n; i++)
        a[i] = sm - a[i];
    sort(a, a + n);
    b[0] = 1;

    for (i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
                a[m++] = a[i];
            b[m - 1]++;
        }

    stp = 0;
    for (i = 0; i < n; i++)
    {
        if (b[i] % x)
        {
            stp = a[i];
            break;
        }

        if ((b[i] > 0) && ((i + 1 >= n) || (a[i + 1] + 1 != a[i])))
        {
            stp = a[i] + 1;
            break;
        }

        b[i + 1] += b[i];
    }

    stp = min(stp, sm);
    cout << binst(x % MOD, stp) << endl;
    return 0;
}

ull binst(ull x, ull n)
{
    if (n == 0)
        return ull(1);

    if (n == 1)
        return x;
    ull bin = binst(x, n / ull(2));
    bin = (bin * bin) % MOD;
    if (n % 2)
        return ((bin * x) % MOD);
    return bin;
}
