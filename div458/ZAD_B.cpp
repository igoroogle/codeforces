#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010], dp[100010];
vector<int> pos;
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    dp[n - 1] = 1;
    pos.pb(n - 1);
    for (int i = n - 2; i >= 0; --i) {
        dp[i] = 2;
        if(pos.empty()) {
            dp[i] = 1;
            pos.pb(i);
            continue;
        }

        while(!pos.empty()) {
            if (a[pos.back() - 1] == a[pos.back()]) {
                pos.pop_back();
                continue;
            }
            dp[i] = 1;
            pos.pb(i);
            break;
        }

    }

    if (dp[0] == 1) {
        cout << "Conan\n";
    } else {
        cout << "Agasa\n";
    }
}
