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

void get_ans(string& vans, string& s, int n) {
    vector<bool> use(10);
    vector<int> col(n);

    for (int i = n - 1; i >= 0; --i) {
        int ind = s[i] - '0';
        for (int j = 0; j < ind; ++j) {
            if (use[j]) {
                col[i] = 2;
            }
        }
        use[ind] = true;
    }

    fill(use.begin(), use.end(), false);


    for (int i = 0; i < n; ++i) {
        int ind = s[i] - '0';
        for (int j = ind + 1; j < 10; ++j) {
            if (use[j]) {
                col[i] = 1;
            }
        }
        use[ind] = true;
    }


    vector<int> to1, to2;
    /*for (int i = 0; i < 10; ++i) {
        if (col[i] == 0) {
            col[i] = 1;
        }
    }*/

    vans.resize(n);
    for (int i = 0; i < n; ++i) {
        if (col[s[i] - '0'] == 1) {
            if ((to1.empty()) || (to1.back() <= int(s[i] - '0'))) {
                to1.pb(int(s[i] - '0'));
                vans[i] = '1';
            } else {
                //vans = "-";
                //return;
                vans[i] = '1';
            }
        } else  if (col[s[i] - '0'] == 1) {
            if ((to2.empty()) || (to2.back() <= int(s[i] - '0'))) {
                to2.pb(int(s[i] - '0'));
                vans[i] = '2';
            } else {
                //vans = "-";
                //return;
                vans[i] = '2';
            }
        } else {
            vans[i] = '0';
        }
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
}
