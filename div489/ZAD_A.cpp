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
    int n, x;
    cin >> n;
    set<int> ans;
    ans.insert(0);
    while (n--) {
        cin >> x;
        ans.insert(x);
    }
    cout << ans.size() - 1 << endl;
}
