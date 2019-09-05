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
    int n;
    cin >> n;
    cin >> s;
    int zer = 0, ed = 0;
    for (auto cur : s) {
        if (cur == '0') {
            ++zer;
        } else {
            ++ed;
        }
    }


    if (ed > 0) {
        cout << '1';
    }

    for (int i = 0; i < zer; ++i) {
        cout << '0';
    }

    cout << '\n';
}
