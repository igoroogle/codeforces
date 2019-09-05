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
int a[27];
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    cin >> n;
    cin >> s;
    if (n == 1) {
        cout << "Yes\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        ++a[s[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (a[i] > 1) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}
