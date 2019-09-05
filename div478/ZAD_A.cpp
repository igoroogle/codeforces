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
    string s;
    cin >> n;
    set<string> ans;
    set<char> w;
    while (n--) {
        cin >> s;
        w.clear();
        for (auto c : s) {
            w.insert(c);
        }

        s.clear();
        s.reserve(w.size());
        for (auto c : w) {
            s.push_back(c);
        }
        ans.insert(s);
    }

    cout << ans.size() << endl;
}
