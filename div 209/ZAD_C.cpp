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
ull a[200010];
ull binst(ull x, ull n);
int main()
{
    ull n, x, i, sm = 0, stp = 0, ost, pw;
    cin >> n >> x;
    for (i = 0; i < n; i++)
        {
            cin >> a[i];
            sm += a[i];
        }

    for (i = 0; i < n; i++)
        a[i] = sm - a[i];
    sort(a, a + n);
    pw = a[0];
    ost = 0;
    if (pw == 0)
        ost = 1;
    for (i = 1; i < n; i++)
    {
        a[i] -= stp;

        if (a[i] == 0)
        {
            ost++;
            continue;
        }

        if ((ost > 0) && (ost % x == 0))
        {
            while (ost > 1)
            {
                pw++;
                ost /= x;
            }
            ost = 0;
        }

        if (ost > 0)
            break;

        if (pw < a[i])
        {
            stp += pw;
            pw = 0;
            break;
        }

        stp += a[i];
        pw -= a[i];
        ost = 1;
        if (pw == 0)
            ost++;
    }


    if (ost == 0)
        stp += pw;
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
