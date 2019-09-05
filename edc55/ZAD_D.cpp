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
int a[510];
bool use[510];

vector<int> ed[510];
vector<int> ar;

int main() {
    ios_base::sync_with_stdio(0);
    int n, u = -1, v = -1, ans = 0, m = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((u == -1) || (a[u] > a[i])) {
            v = u;
            u = i;
        } else if ((v == -1) || (a[v] > a[i])) {
            v = i;
        }
    }
    use[u] = true;
    use[v] = true;
    int cur = u;

    for(;;) {
        int ind = -1;
        for (int i = 0; i < n; ++i) {
            if ((!use[i]) && (a[i] > 1)) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            break;
        }
        --a[cur];
        use[ind] = true;
        ed[cur].pb(ind);
        ++m;
        ++ans;
        cur = ind;
        --a[cur];
    }

    --a[cur];
    ed[cur].pb(v);
    ++m;
    ++ans;
    --a[v];
    use[v] = true;



    for (int i = 0; i < n; ++i) {
        if (!use[i]) {
            ar.pb(i);
        }
    }

    for (auto cur : ar) {
        int ind = -1;
        for (int j = 0; j < n; ++j) {
            if ((use[j]) && (a[j] > 0)) {
                    ind = j;
                    break;
                }
            }

            if (ind == -1) {
                cout << "NO\n";
                return 0;
            }

            --a[ind];
            ed[ind].pb(cur);
            ++m;

    }


    cout << "YES " << ans << '\n';
    cout << m << '\n';
    /*m = 0;
    for (int i = 0; i < n; ++i) {
        for (auto cur : ed[i]) {
            ++m;
        }
    }
    cout << m << endl;*/

    for (int i = 0; i < n; ++i) {
        for (auto cur : ed[i]) {
            cout << i + 1 << ' ' << cur + 1 << '\n';
        }
    }

}
