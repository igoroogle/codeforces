#define pb push_back
#define mp make_pair
#define x first
#define y second
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2E18;
char s[200010];
set< pair<int, pair<int, int> > > t;
vector<int> ans;

int main() {
    int n, i, a, b, k, ind = -1, val, sm = 0, l, r, m;
    cin >> n >> a >> b >> k;
    scanf("%s", &s);
    s[n++] = '1';
    for (i = 0; i < n; ++i) {
        if (s[i] == '1') {
            val = i - ind - 1;
            if (val >= b) {
                t.insert(mp(-val, mp(ind + 1, i - 1)));
                sm += val / b;
            }

            ind = i;
        }
    }

    while (sm >= a) {
        val = -(t.begin()->x);
        l = t.begin()->y.x;
        r = t.begin()->y.y;
        t.erase(t.begin());
        sm -= val / b;
        m = l + b - 1;
        ans.pb(m);
        if (m - l >= b) {
            t.insert(mp(-(m - l), mp(l, m - 1)));
            sm += (m - l) / b;
        }

        if (r - m >= b) {
            t.insert(mp(-(r - m), mp(m + 1, r)));
            sm += (r - m) / b;
        }

    }

    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i] + 1);
    }
    cout << endl;
}
