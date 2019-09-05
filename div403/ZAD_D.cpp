#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
bool use1[3010], use2[3010], use3[3010];
int fr[3010], sc[3010], kl = 1, n;
unordered_map<string, int> tv;
vector<int> bg1, bg2, bg3, a[3010], b[3010];
int ans[3010];
string s1, s2, s, t, val[3010];
bool go_next1(int v, int p);
bool go_next2(int v, int p);
bool dfs(int v, int typ);
bool go_next1(int v, int p) {
    int i;
    for (auto vl : a[v]) {
        if (vl == p) {
            continue;
        }


        if (!use1[vl]) {
            if (use3[sc[vl]]) {
                return false;
            }

            if (!dfs(vl, 1)) {
                return false;
            }
        } else {
            if (ans[vl] == 2) {
                return false;
            }
        }
    }

    return true;
}


bool go_next2(int v, int p) {
    int i;
    for (auto vl : b[v]) {
        if (vl == p) {
            continue;
        }

        if (!use1[vl]) {
            if (use2[fr[vl]]) {
                return false;
            }

            if (!dfs(vl, 0)) {
                return false;
            }
        } else {
            if (ans[vl] == 1) {
                return false;
            }
        }
    }

    return true;
}

bool dfs(int v, int typ) {
    if (typ == 0) {
        use1[v] = true;
        bg1.pb(v);

        use2[fr[v]] = true;
        bg2.pb(fr[v]);

        use3[fr[v]] = true;
        bg3.pb(fr[v]);

        ans[v] = 1;
        /*if (a[fr[v]].size() > 1) {
            return false;
        }*/

        if (!go_next1(fr[v], v))
            return false;
        if (!go_next2(fr[v], v))
            return false;
        return true;
    } else {
        use1[v] = true;
        bg1.pb(v);

        use2[sc[v]] = true;
        bg2.pb(sc[v]);

        use3[sc[v]] = true;
        bg3.pb(sc[v]);

        use2[fr[v]] = true;
        bg2.pb(fr[v]);

        ans[v] = 2;
        if (!go_next1(sc[v], v))
            return false;
        if (!go_next2(sc[v], v))
            return false;
        if (!go_next1(fr[v], v))
            return false;
        return true;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int x, y, i, cur1, cur2, cur3;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        s = s1.substr(0, 3);
        t = s1.substr(0, 2) + s2.substr(0, 1);
        if (tv[s] == 0) {
            x = kl++;
            tv[s] = x;
            val[x] = s;
        } else {
            x = tv[s];
        }

        if (tv[t] == 0) {
            y = kl++;
            tv[t] = y;
            val[y] = t;
        } else {
            y = tv[t];
        }

        fr[i] = x;
        sc[i] = y;
        a[x].pb(i);
        b[y].pb(i);
    }

    for (i = 0; i < n; ++i) {
        if (use1[i]) {
            continue;
        }

        cur1 = bg1.size();
        cur2 = bg2.size();
        cur3 = bg3.size();
        if (dfs(i, 0)) {
            continue;
        }

        while (bg1.size() > cur1) {
            use1[bg1[bg1.size() - 1]] = false;
            bg1.pop_back();
        }

        while (bg2.size() > cur2) {
            use2[bg2[bg2.size() - 1]] = false;
            bg2.pop_back();
        }

        while (bg3.size() > cur3) {
            use3[bg2[bg3.size() - 1]] = false;
            bg3.pop_back();
        }

        if (dfs(i, 1)) {
            continue;
        }

        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (i = 0; i < n; ++i) {
        if (ans[i] == 1)
            cout << val[fr[i]] << endl;
        else {
            cout << val[sc[i]] << endl;
        }
    }
}
