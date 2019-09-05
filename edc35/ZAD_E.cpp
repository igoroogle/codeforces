#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1E9;
int a[200010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    set<int> vl;
    vl.insert(INF);
    for (int i = 1; i <= n; ++i) {
        vl.insert(-i);
    }

    int mx = -INF;
    for (int i = 1; i <= n; ++i) {
        if (i <= k) {
            cin >> a[i - 1];
            mx = max(mx, a[i - 1]);
            vl.erase(-a[i - 1]);
            continue;
        }

        auto cur = vl.lower_bound(-mx);
        //cout << *cur << endl;
        if (*cur != INF) {
            //cout << -(*cur) << endl;
            a[i - 1] = -(*cur);
            vl.erase(*cur);
            continue;
        }

        a[i - 1] = -(*vl.begin());
        vl.erase(*vl.begin());
    }

    int nx = 1;
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        st.push(a[i]);
        while ((!st.empty()) && (st.top() == nx)) {
            st.pop();
            ++nx;
        }
    }

    if (!st.empty()) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}
