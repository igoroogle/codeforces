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
const ull PL = 62;

ull pw[PL], nw[PL];
vector<int> a, kval, smval;

ull get(ull x) {

}

int main() {
    ios_base::sync_with_stdio(0);
    set<ull> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ull x;
        cin >> x;
        s.insert(x);
    }

    while (!s.empty()) {
        a.pb(*s.begin());
        s.erase(s.begin());
    }
    ull diff = s.size();

    for (size_t i = 1; i < a.size(); ++i) {
        kval.pb(a[i] - a[i - 1]);
    }

    if (!kval.empty()) {
        sort(kval.begin(), kval.end());
        smval.resize(kval.size());
    }

    pw[0] = 0;
    nw[0] = 0;
    int j = 0;
    for (int i = 1; i < PL; ++i) {
        pw[i] = (pw[i - 1] << ull(1));
        if (j < int(kval.size())) {
            smval[j] = 0;
        }

        while ((j < int(kval.size())) && (kval[j] <= (ull(1) << ull(i)))) {
            ++nw[i];
            ++smval[j];
            ++j;
            if (j < int(kval.size())) {
                smval[j] = smval[j - 1];
            }
        }
        pw[i] += nw[i];
    }

    int q;
    cin >> q;
    while (q--) {
        ull l1, r1;
        cin >> l1 >> r1;
        ull x = r1 - l1;
        if (x == 0) {
            cout << diff << '\n';
            continue;
        }

        ull ans = diff * (x + ull(1));
        ans -= get(x + ull(1));
        cout << ans << '\n';
    }
}
