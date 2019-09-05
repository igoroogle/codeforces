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
pair<int, int> a[111];

bool use[5010];
int kol[5010];

int go_inc(int l, int r, int stp) {
    int ans = 0;
    for (int i = l; i != r + stp; i += stp) {
        if (use[i]) {
            ++ans;
            continue;
        } else {
            kol[i - stp] += kol[i];
            use[i] = true;
            ans += kol[i] + 2;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    fill(kol, kol + n, 1);
    --k;
    int ans = 0;
    if (k == 0) {
        --kol[0];
        ++kol[1];
        ans += 2;
        use[0] = true;
        ans += go_inc(1, n - 1, 1);
    } else if (k == n - 1) {
        ++kol[n - 2];
        --kol[n - 1];
        use[n - 1] = true;
        ans += 2;
        ans += go_inc(n - 2, 0, -1);
    } else if (n - k - 1 > k) {
        ++kol[k - 1];
        --kol[k];
        use[k] = true;
        ans += 2;
        ans += go_inc(k - 1, 0, -1);
        ans += go_inc(1, n - 1, 1);
    } else {
        ++kol[k + 1];
        --kol[k];
        use[k] = true;
        ans += 2;
        ans += go_inc(k + 1, n - 1, 1);
        ans += go_inc(n - 2, 0, -1);
    }

    cout << ans << '\n';
}
