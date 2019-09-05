#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ull MOD = 998244353;
const ull SQ2 = 1414213563;
const ull SQ3 = 1259923;
const ull SQ4 = 37607;
const ull DL = 337;
const ull ML = 333;

ull ssq2(ull n)
{
    ull l = 2, r = SQ2;
    while (l < r) {
        ull m = (l + r) >> ull(1);
        if (m * m < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

ull ssq3(ull n)
{
    ull l = 2, r = SQ3;
    while (l < r) {
        ull m = (l + r) >> ull(1);
        if (m * m * m < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

ull ssq4(ull n)
{
    ull l = 2, r = SQ4;
    while (l < r) {
        ull m = (l + r) >> ull(1);
        if (m * m * m * m < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}


ull gcd(ull a, ull b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ull binst(ull x, ull y, ull n)
{
    ull ans, t;
    if (y == 0)
        return 0;
    if (y == 1)
        return x;
    ans = binst(x, y / 2, n);
    if (y % 2)
    {
        if (n - ans > ans)
            t = ans + ans;
        else
            t = ans - n + ans;
        if (n - t > x)
            t = t + x;
        else
            t = x - n + t;
        return t;
    }
    else
    {
        if (n - ans > ans)
            t = ans + ans;
        else
            t = ans - n + ans;
        return t;
    }
}

ull rho(ull n)
{
    if (!(ull(n) % ull(2)))
        return ull(2);
    ull x = ull(2);
    //ull x = ((ull(rand()) << ull(45)) ^ (ull(rand()) << ull(30)) ^ (ull(rand()) << ull(15)) ^ (ull(rand()))) % (ull(n) - ull(2)) + ull(1);
    ull y = 1, i = 0, st = 2;
    ld t;
    while(gcd(n, max(x, y) - min(x, y)) == ull(1))
    {
        if (i > ML)
            return ull(n);

        if (i == st)
        {
            y = x;
            st *= ull(2);
        }

        x = binst(x, x, n);
        t = x + 1;
        if (t > n)
            t = t - n;
        x = t;
        i++;
    }
    return gcd(n, max(x, y) - min(x, y));
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ull x;
    cin >> n;
    vector<ull> ans;
    vector<ull> ansz;
    vector<ull> ansy;
    vector<bool> anszb;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        bool f = true;
        for (ull i = 2; i <= DL; ++i) {
            if (x % i == ull(0)) {
                while (x % i == 0) {
                    ans.pb(i);
                    f = false;
                    x /= i;
                }
            }
        }

        ull y;


        /*if (f) {
            for (int k = 0; k < 3; ++k) {
                y = rho(x);
                //cout << y << endl;
                if (y != ull(x)) {
                    while (x % y == ull(0)) {
                        ans.pb(y);
                        x /= y;
                    }
                    f = false;
                }
            }
        }*/


        y = ssq2(x);
        while (x % y == ull(0)) {
            ans.pb(y);
            f = false;
            x /= y;
        }

        y = ssq3(x);
        while (x % y == ull(0)) {
            ans.pb(y);
            f = false;
            x /= y;
        }

        y = ssq4(x);
        while (x % y == ull(0)) {
            ans.pb(y);
            f = false;
            x /= y;
        }

        if (f) {
            ansz.pb(x);
            anszb.pb(true);
        } else if (x > 1) {
            ans.pb(x);
        }
    }


    for (size_t i = 0; i < ansz.size(); ++i) {
        for (size_t j = i + 1; j < ansz.size(); ++j) {
            if (ansz[i] == ansz[j]) {
                continue;
            }

            ull gd = gcd(ansz[i], ansz[j]);
            if (gd > ull(1)) {
                if (anszb[i]) {
                    anszb[i] = false;
                    ans.pb(gd);
                    ans.pb(ansz[i] / gd);
                }

                if (anszb[j]) {
                    anszb[j] = false;
                    ans.pb(gd);
                    ans.pb(ansz[j] / gd);
                }
            }
        }

        if (anszb[i]) {
            for (auto cur : ans) {
                if (ansz[i] % cur == 0) {
                    ans.pb(ansz[i] / cur);
                    ans.pb(cur);
                    anszb[i] = false;
                    break;
                }
            }
        }

        if (anszb[i]) {
            ansy.pb(ansz[i]);
        }
    }

    sort(ans.begin(), ans.end());
    sort(ansy.begin(), ansy.end());
    vector<ull> vl;
    vl.pb(ull(1));

    for (size_t i = 1; i < ans.size(); ++i) {
        if (ans[i] == ans[i - 1]) {
            ++vl.back();
        } else {
            vl.pb(ull(1));
        }
    }

    ull ansv = 1;
    if (!ans.empty()) {
        for (auto cur : vl) {
            ansv = (ansv * (cur + ull(1))) % MOD;
        }
    }

    vl.clear();
    vl.pb(ull(1));
    for (size_t i = 1; i < ansy.size(); ++i) {
        if (ansy[i] == ansy[i - 1]) {
            ++vl.back();
        } else {
            vl.pb(ull(1));
        }
    }

    if (!ansy.empty()) {
        for (auto cur : vl) {
            ansv = (ansv * (cur + ull(1))) % MOD;
            ansv = (ansv * (cur + ull(1))) % MOD;
        }
    }

    cout << ansv << '\n';
}
