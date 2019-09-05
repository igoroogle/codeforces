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
int p[1010], par[1010];
bool use[1010];

int main() {
    //ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * 2; ++i) {
        cin >> p[i];
        par[i] = -1;
    }

    while(m--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        par[a] = b;
        par[b] = a;
    }

    int oth = -1;
    int t;
    cin >> t;
    --t;

    for (int i = 0; i < n + n; ++i) {
        if (t) {
            int x;
            cin >> x;
            --x;
            use[x] = true;
            oth = par[x];
        } else {
            if ((oth != -1) && (!use[oth])) {
                use[oth] = true;
                cout << oth + 1 << endl;
                t ^= 1;
                continue;
            }

            int ind = -1;
            for (int j = 0; j < n + n; ++j) {
                if (use[j]) {
                    continue;
                }

                if (par[j] != -1) {
                    if (p[j] > p[par[j]]) {
                        ind = j;
                    } else {
                        ind = par[j];
                    }
                    break;
                }

                if ((ind == -1) || (p[ind] < p[j])) {
                    ind = j;
                }
            }

            use[ind] = true;
            cout << ind + 1 << endl;
        }
        t ^= 1;
    }
}
