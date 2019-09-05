#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;

bool squar(int n) {
    int sq = sqrt(ld(n));
    if (sq * sq == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, p = -1, ans, kl, toAns = -1;
    cin >> n;
    vector<int> ar;
    m = n;

    while (m > 0) {
        ar.pb(m % 10);
        m /= 10;
    }
    reverse(ar.begin(), ar.end());

    for (int i = 1; i < (1 << ar.size()); ++i) {
        p = -1;
        ans = 0;
        kl = 0;
        for (int j = 0; j < 10; ++j) {
            if (i & (1 << j)) {
                ++kl;
                if (p == -1) {
                    p = ar[j];
                }
                ans = ans * 10 + ar[j];
            }
        }
        if ((p != 0) && (squar(ans))) {
            toAns = max(kl, toAns);
        }
    }

    if (toAns != -1) {
        toAns = ar.size() - toAns;
    }
    cout << toAns << endl;
}
