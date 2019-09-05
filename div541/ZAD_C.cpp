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
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    multiset<int> t;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        t.insert(x);
    }

    int start = *t.begin();
    t.erase(t.begin());
    vector<int> a, b;
    while (!t.empty()) {
        a.pb(*t.begin());
        t.erase(t.begin());
        if (!t.empty()) {
            b.pb(*t.begin());
            t.erase(t.begin());
        }
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        cout << a[i] << ' ';
    }
    cout << start << ' ';
    for (auto cur : b) {
        cout << cur << ' ';
    }
}
