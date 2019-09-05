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
int vl[27];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 27; ++j) {
            vl[j] = 0;
        }

        for (int j = i; j < n; ++j) {
            ++vl[s[j] - 'a'];
            bool f = true;
            for (int k = 0; k < 27; ++k) {
                if (vl[k] > (j - i + 1) / 2) {
                    f = false;
                    break;
                }
            }

            if (f) {
                cout << "YES\n";
                for (int k = i; k <= j; ++k) {
                    cout << s[k];
                }
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "NO\n";
}
