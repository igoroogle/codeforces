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
int pos[100010];

int main() {
    ios_base::sync_with_stdio(0);
    vector<vector<int>> ans, ansOld;
    vector<int> curAns;
    int n, m, x;
    cin >> n >> m;
    curAns.clear();
    curAns.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        --x;
        curAns.pb(x);
    }
    ans.pb(curAns);

    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            --x;
            pos[x] = j;
        }
        ansOld = ans;
        ans.clear();
        for (auto& vl : ansOld) {
            curAns.clear();
            curAns.pb(vl.front());
            for (size_t j = 1; j < vl.size(); ++j) {
                if (pos[curAns.back()] + 1 == pos[vl[j]]) {
                    curAns.pb(vl[j]);
                } else {
                    ans.pb(curAns);
                    curAns.clear();
                    curAns.pb(vl[j]);
                }
            }
            ans.pb(curAns);
        }
    }

    ll vans = 0;
    for (auto& vl : ans) {
        vans += ll(vl.size() + 1) * ll(vl.size()) / ll(2);
    }

    cout << vans << '\n';
}
