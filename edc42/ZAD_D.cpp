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
set<ll> ans;
set<ll> indx[300011];
map<ll, ll> getInd;
ll kl = 0;
ll a[300010];
bool use[300010];

int main() {
    ios_base::sync_with_stdio(0);
    ll n, x, ind, ansVal = 0, lf, rf;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = x;
        if (getInd[x] == 0) {
            ind = ++kl;
            getInd[x] = ind;
        } else {
            ind = getInd[x];
        }
        indx[ind].insert(i);
        if (indx[ind].size() == 2) {
            ans.insert(x);
        }
    }

    while (!ans.empty()) {
        ++ansVal;
        x = *ans.begin();
        if (getInd[x] == 0) {
            ind = ++kl;
            getInd[x] = ind;
        } else {
            ind = getInd[x];
        }
        lf = *indx[ind].begin();
        rf = *indx[ind].upper_bound(lf);
        indx[ind].erase(lf);
        indx[ind].erase(rf);
        if (indx[ind].size() < 2) {
            ans.erase(x);
        }

        use[lf] = true;
        x = x + x;
        a[rf] = x;

        if (getInd[x] == 0) {
            ind = ++kl;
            getInd[x] = ind;
        } else {
            ind = getInd[x];
        }
        indx[ind].insert(rf);
        if (indx[ind].size() == 2) {
            ans.insert(x);
        }
    }

    cout << n - ansVal << endl;
    for (ll i = 1; i <= n; ++i) {
        if (!use[i]) {
            cout << a[i] << ' ';
        }
    }
}
