#include<bits/stdc++.h>>

using namespace std;
typedef long long ll;
typedef long double ld;

int f[2][100010];

void upd(int ind, int x, int n, int t) {
    while (ind <= n) {
        f[t][ind] = max(f[t][ind], x);
        ind |= (ind + 1);
    }
}

int get(int ind, int n, int t) {
    int ans = 0;
    while (ind >= 0) {
        ans = max(f[t][ind], ans);
        ind = (ind & (ind + 1)) - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> a, ra;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            a.push_back(s);
            reverse(s.begin(), s.end());
            ra.push_back(s);
        }
        sort(a.begin(), a.end());
        sort(ra.begin(), ra.end());
        map<string, int> pos, rpos;
        int posV = 0, rposV = 0;
        for (int i = 0; i < n; ++i) {
            if ((i == 0) || (a[i - 1] != a[i])) {
                pos[a[i]] = posV;
                ++posV;
            }

            if ((i == 0) || (ra[i - 1] != ra[i])) {
                rpos[ra[i]] = rposV;
                ++rposV;
            }
        }

        for (int i = 0; i <= n; ++i) {
            f[0][i] = 0;
            f[1][i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            if ((i > 0) && (a[i] == a[i - 1])) {
                continue;
            }

            auto s = a[i];
            reverse(s.begin(), s.end());
            int ind = rpos[s];
            if (s.find("m") != string::npos) {
                upd(ind + 1, get(ind, n, 0) + 1, n, 1);
            } else {
                upd(ind + 1, get(ind, n, 0) + 1, n, 0);
                upd(ind + 1, get(ind, n, 1) + 1, n, 1);
            }
        }

        cout << get(n, n, 1) << '\n';
    }

    return 0;
}
