#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define em emplace_back
#define sqr(x) ((x) * (x))
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> mt = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    ios_base::sync_with_stdio(0);
    vector<int> an;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        an.pb(x);
    }

    bool f = false;
    for (size_t i = 0; i < mt.size() - n + 1; ++i) {
        f = true;
        for (size_t j = i; j < i + n; ++j) {
            if (mt[j] != an[j - i]) {
                f = false;
                break;
            }
        }
        if (f) {
            break;
        }
    }

    if (f) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
