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
const ll INF = 2E18;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    string st;
    cin >> n >> st;
    int g = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        if (st[i] == 'G') {
            ++g;
        } else {
            ++s;
        }
    }

    int l = 0, vg = 0, vs = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            ++vg;
        } else {
            ++vs;
        }

        while (vs > 1) {
            if (s[l] == 'G') {
                --vg;
            } else {
                --vs;
            }
            ++l;
        }

        ans = max(vg, ans);
    }
}
