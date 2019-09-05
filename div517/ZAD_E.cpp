#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef unsigned int uni;
typedef long long ll;
typedef long double ld;
int a[100001];

int main() {
    ios_base::sync_with_stdio(0);
    int n, ost = 0;
    vector<int> ed, zer;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ost = (ost + a[i]) % 3;
        if (a[i]) {
            ed.pb(i);
        } else {
            zer.pb(i);
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    if (ost != 0)
        if (int(ed.size()) >= 5) {
            ans.pb(mp(ed[0], ed[1]), ed[2]);
            a[ed[0]] = 0;
            a[ed[1]] = 0;
            a[ed[2]] = 0;
            if ()
        }
    }

}
