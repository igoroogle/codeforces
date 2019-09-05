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

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    /*int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ++ans;
            for (int k = 0; k < (j - i + 1) / 2; ++k) {
                if (s[k + i] != s[j - k]) {
                    --ans;
                    break;
                }
            }
        }
    }

    cout << ans << endl;*/
    cout << s << '\n';
}
