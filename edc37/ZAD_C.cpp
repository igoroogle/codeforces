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
int a[200010];
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> s;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if ((i == n - 1) || (s[i] == '0')) {
            sort(a + l, a + i + 1);
            l = i + 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}
