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
const int INF = 1E9 + 7;
const string ST_VAL = "ACTG";

int comp_it(char x, char y) {
    int ans = 0;
    if (x > y) {
        swap(x, y);
    }
    ans = y - x;
    ans = min('Z' - y + x - 'A' + 1, ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = INF;
    for (int i = 0; i < n - 3; ++i) {
        int vl = 0;
        for (int j = 0; j < 4; ++j) {
            vl += comp_it(st[i + j], ST_VAL[j]);
        }
        ans = max(vl, ans);
    }

    cout << ans << endl;
}
