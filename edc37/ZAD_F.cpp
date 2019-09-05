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
vector<int> pr;
int main() {
    ios_base::sync_with_stdio(0);
    int ans = 0;
    for (int i = 2; i < 1003; ++i) {
        pr.pb(i);
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                pr.pop_back();
                break;
            }
        }
    }
    cout << pr.size() << endl;
    for (auto cur : pr) {
        cout << cur << ' ';
    }
}
