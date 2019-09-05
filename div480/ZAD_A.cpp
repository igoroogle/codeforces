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
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto cur : s) {
        if (cur == 'o') {
            ++a;
        } else {
            ++b;
        }
    }

    if ((a == 0) || (b % a == 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
