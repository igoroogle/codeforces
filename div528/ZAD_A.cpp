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
    string s, ans;
    cin >> s;
    int n = s.length();
    --n;
    int i = n / 2;
    cout << s[i];
    for (int j = 1; (i + j) <= n; ++j) {
        cout << s[i + j];
        if (i - j >= 0) {
            cout << s[i - j];
        }
    }
    cout << '\n';
}
