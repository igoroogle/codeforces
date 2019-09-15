#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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

<<<<<<< HEAD
int main() {
    ios_base::sync_with_stdio(0);

=======
void get_ans(string& vans, string& s, int n) {
    vans.resize(n);
    string sb = s;
    sort(sb.begin(), sb.end());
    string s1, s2;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == sb[j]) {
            vans[i] = '1';
            s1.pb(s[i]);
            ++j;
        } else {
            s2.pb(s[i]);
            vans[i] = '2';
        }
    }

    if (s1 + s2 != sb) {
        vans = "-";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
        get_ans(ans, s, n);
        cout << ans << '\n';
    }
>>>>>>> d8d6029b0d4d50aced12f72c1225ce1e66cb2824
}
