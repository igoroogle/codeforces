#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef long double ld;
using namespace std;
ll al[29];
vector< pair<char, char> > ans;
string s, t;
int main() {
    int i;
    cin >> s >> t;
    for (i = 0; i < s.length(); ++i) {
        if ((al[int(s[i] - 'a' + 1)] == 0) && (al[int(t[i] - 'a' + 1)] == 0)) {
            al[int(s[i] - 'a' + 1)] = int(t[i] - 'a' + 1);
            al[int(t[i] - 'a' + 1)] = int(s[i] - 'a' + 1);
            if (s[i] != t[i]) {
                ans.pb(mp(s[i], t[i]));
            }

            continue;
        } else if ((al[int(s[i] - 'a' + 1)] != 0) && (al[int(t[i] - 'a' + 1)] != 0) && (al[int(s[i] - 'a' + 1)] == int(t[i] - 'a' + 1))) {
            continue;
        }

        //cout << i << ' ' << al[int(s[i] - 'a' + 1)]   << ' ' << al[int(t[i] - 'a' + 1)] << endl;
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); ++i) {
        cout << ans[i].x << ' ' << ans[i].y << "\n";
    }
}
