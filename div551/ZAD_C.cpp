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
const int INF = 1E9;
int ans[300010];
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    cin >> n >> s;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = ans[i + 1];
        if (s[i - 1] == '(') {
            --ans[i];
        } else {
            ++ans[i];
        }
    }

    int bal = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++bal;
        } else if (s[i] == ')') {
            --bal;
        } else if (s[i] == '?') {
            if (bal + 1 <= ans[i + 1]) {
                s[i] = '(';
                ++bal;
            } else {
                s[i] = ')';
                --bal;
            }
        }

        if (i == n - 1) {
            break;
        }

        if (bal <= 0) {
            cout << ":(\n";
            return 0;
        }
    }

    if (bal != 0) {
        cout << ":(\n";
        return 0;
    }

    cout << s << '\n';
}
