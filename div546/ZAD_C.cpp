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

int a[503][503], b[503][503];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    int st_i = 0, st_j = 0;

    multiset<int> s_a, s_b;
    for(;;) {
        int i = st_i;
        int j = st_j;

        while ((i < n) && (j >= 0)) {
            s_a.insert(a[i][j]);
            s_b.insert(b[i][j]);
            ++i;
            --j;
        }

        while (!s_a.empty()) {
            if ((*s_a.begin()) == (*s_b.begin())) {
                s_a.erase(s_a.begin());
                s_b.erase(s_b.begin());
            } else {
                cout << "NO\n";
                return 0;
            }
        }

        if (st_j + 1 < m) {
            ++st_j;
        } else if (st_i + 1 < n) {
            ++st_i;
        } else {
            break;
        }
    }

    cout << "YES\n";
}
