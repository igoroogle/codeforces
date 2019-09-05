#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
int par[200010];
bool use[200010];
vector<int> sc;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
                sc.pb(i);
        } else {
            par[i] = sc.back();
            par[sc.back()] = i;
            sc.pop_back();
        }
    }

    int j = 0;
    for (int i = 0; i < (n - k) / 2; ++i) {
        while (use[j]) {
            ++j;
        }
        use[j] = true;
        use[par[j]] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!use[i]) {
            cout << s[i];
        }
    }
    cout << '\n';
}
