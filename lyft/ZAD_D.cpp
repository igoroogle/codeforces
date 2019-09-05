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
const ull DL = 1259921;
const ull ML = 1003;


ull gcd(ull a, ull b)
{
    if (a == 0)
        return max(b, ull(1));
    else if (b == 0)
        return max(ull(1), a);
    else
        return gcd(b, a % b);
}

ull ssq(ull n)
{
    ull sq = ull(sqrt(ld(n)));
    if (sq > 2)
        sq -= ull(2);
    else
        sq = 0;

    while (ull(sq + 1) * ull(sq + 1) <= n)
        sq++;

    if (sq < ull(2)) {
        sq = ull(2);
    }

    return sq;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ull x;
    cin >> n;
    vector<ull> ans, vvl;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        vvl.pb(x);
    }

    for (int i = 0; i < n; ++i) {
        x = vvl[i];

        for (ull i = 0; i < int(vvl.size()); ++i) {
            ull y = gcd(x, y);

        }
        for (ull i = 2; i <= DL; ++i) {
            if (x % i == ull(0)) {
                while (x % i == 0) {
                    ans.pb(i);
                    x /= i;
                }
            }
        }

        ull y = ssq(x);
        while (x % y == ull(0)) {
            ans.pb(y);
            x /= y;
        }

        if (x > ull(1)) {
            ans.pb(x);
        }
    }

    sort(ans.begin(), ans.end());
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
    for (auto cur : vl) {
        ansv = (ansv * (cur + ull(1))) % MOD;
    }

    cout << ansv << '\n';
}
