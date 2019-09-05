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
const int DL = 5003;
int st[DL];
vector<int> a[DL];
bool use[DL];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(0);
    int t, n, l, r, tim;
    cin >> t;
    while (t--) {
        cin >> n;

        tim = 0;
        for (int i = 0; i < n; ++i) {
            st[i] = 0;
            cin >> l >> r;
            a[r].pb(i);
            while (tim < l) {
                while (!q.empty()) {
                    if (use[q.front()]) {
                        use[q.front()] = false;
                        st[q.front()] = tim;
                        q.pop();
                        break;
                    }
                    q.pop();
                }
                while (!a[tim].empty()) {
                    use[a[tim].back()] = false;
                    a[tim].pop_back();
                }
                ++tim;
            }
            q.push(i);
            use[i] = true;
        }

        while (tim < DL) {
                while (!q.empty()) {
                    if (use[q.front()]) {
                        use[q.front()] = false;
                        st[q.front()] = tim;
                        q.pop();
                        break;
                    }
                    q.pop();
                }
                while (!a[tim].empty()) {
                    use[a[tim].back()] = false;
                    a[tim].pop_back();
                }
                ++tim;
            }

        for (int i = 0; i < n; ++i) {
            cout << st[i] << ' ';
        }
        cout << '\n';
    }
}
