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
set<char> c;
vector<char> a;
int vl[27];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    string s, t, a;
    cin >> n >> k;
    cin >> s;
    for (auto cur : s) {
        c.insert(cur);
    }

    for (auto cur = c.begin(); cur != c.end(); ++cur) {
        a.pb(*cur);
        vl[int(*cur - 'a')] = a.size() - 1;
    }

    if (k > n) {
        t = s;
        t.resize(k);
        for (int i = n; i < k; ++i) {
            t[i] = a[0];
        }
        cout << t << '\n';
        return 0;
    }

    t.resize(k);
    for (int i = 0; i < k; ++i) {
        t[i] = s[i];
    }

    for (int i = k - 1; i >= 0; --i) {
        if (t[i] < a.back()) {
            t[i] = a[vl[int(t[i] - 'a')] + 1];
            for (int j = i + 1; j < k; ++j) {
                t[j] = a[0];
            }
            break;
        }
    }

    cout << t << '\n';
}
