#include<algorithm>
#include<map>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
const ll DL = 400003;
const ll PP = 20;
const ll INF = 3E18 + 3;
ll last = 0;
ll cnt = 1, q;
ll w[DL], par[PP][DL], sm[PP][DL];
void ask (ll t, ll r, ll x) {
    ll u;
    if (t == 1) {
        ++cnt;
        w[cnt] = x;
        par[0][cnt] = r;
        sm[0][cnt] = w[r];
        if (w[r] < w[cnt]) {
            par[0][cnt] = -1;
            sm[0][cnt] = INF;
        }
        for (int i = 1; i < PP; ++i) {
            if (par[i - 1][cnt] == -1) {
                par[i][cnt] = -1;
                sm[i][cnt] = INF;
            } else {
                u = par[i - 1][par[i - 1][cnt]];
                if (u == -1) {
                    par[i][cnt] = -1;
                    sm[i][cnt] = INF;
                } else {
                    par[i][cnt] = u;
                    sm[i][cnt] = sm[i - 1][cnt] + sm[i - 1][u];
                }
            }
        }
    } else {
        ll ans = 0;
        ll vl = PP - 1, ssm = 0;
        u = r;
        while ((r != -1) || (vl > 0)) {
            while (par[r][]) {

            }
            --vl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    w[1] = 1;
    for (int i = 0; i < PP; ++i) {
        par[i][1] = -1;
        sm[i][1] = INF;
    }
    ll q, t, r, x;
    cin >> q;
    while (q--) {
        cin >> t >> r >> x;
        ask(t, r ^ last, x ^ last);
    }
}
