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
int ans[27];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (i - l + 1 == k) {
            ++ans[s[i] - 'a'];
            l = i + 1;
            continue;
        }

        if (i + 1 > n) {
            break;
        }

        if (s[i + 1] != s[i]) {
            l = i + 1;
        }
    }

    int ansv = 0;
    for (int i = 0; i < 26; ++i) {
        ansv = max(ans[i], ansv);
    }

    cout << ansv << '\n';
}
