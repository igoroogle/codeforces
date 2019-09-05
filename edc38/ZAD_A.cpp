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
const ll INF = 2E18 + 3;
bool check(char c) {
    if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'y')) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    bool f;
    int n;
    cin >> n;
    cin >> s;
    while (!s.empty()) {
        f = true;
        for (size_t i = 1; i < s.length(); ++i) {
            if ((check(s[i])) && (check(s[i - 1]))) {
                f = false;
                s.erase(i, 1);
                break;
            }
        }
        if (f) {
            break;
        }
    }
    cout << s << endl;
}
