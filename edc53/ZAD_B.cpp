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
bool use[200010];

int main() {
    ios_base::sync_with_stdio(0);
    queue<int> q;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        use[x] = true;
        q.push(x);
    }

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (!use[x]) {
            cout << 0 << ' ';
            continue;
        }

        int ans = 0, vl = -1;
        while (vl != x) {
            vl = q.front();
            use[vl] = false;
            q.pop();
            ++ans;
        }
        cout << ans << ' ';
    }

}
