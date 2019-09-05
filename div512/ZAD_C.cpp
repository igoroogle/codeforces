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
const int DL = 903;

bool dp[103][904];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    string s;
    cin >> n;
    cin >> s;

    for (int i = 0; i < DL; ++i) {
        dp[0][i] = true;
    }

    for (int i = 1; i < n; ++i) {
        int sm = 0;
        for (int j = i; j > 0; --j) {
            sm += int(s[j - 1] - '0');
            if (dp[j - 1][sm]) {
                dp[i][sm] = true;
            }
        }
    }

    int sm = 0;
    for (int i = n; i > 1; --i) {
        sm += int(s[i - 1] - '0');
        if (dp[i - 1][sm]) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
