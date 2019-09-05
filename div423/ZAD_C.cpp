#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const int INF = 1E9;
const int DL = 3000003;
string val[3000010];
int a[3000010];
char an[3000010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, i, j, cur = 0, k, x, ind = -1, m = 0;
    cin >> n;

    for (i = 0; i < DL; ++i) {
        a[i] = -1;
        val[i] = "";
    }

    for (i = 0; i < n; ++i) {
        cin >> val[i] >> k;
        for (j = 0; j < k; ++j) {
            cin >> x;
            --x;
            m = max(m, x + int(val[i].length()));
            if ((a[x] == -1) || (val[i].length() > val[a[x]].length())) {
                a[x] = i;
            }
        }
    }


    for (i = 0; i < m; ++i) {
        an[i] = 'a';
    }

    for (i = 0; i < m; ++i) {
        if (a[i] != -1) {
            if ((ind == -1) || (cur >= val[ind].length()) || (val[ind].length() - cur <= val[a[i]].length())) {
                cur = 0;
                ind = a[i];
            }
        }

        if ((ind != -1) && (cur >= val[ind].length())) {
            ind = -1;
        }

        if (ind != -1) {
            an[i] = val[ind][cur];
            ++cur;
        }
    }

    cout << an << endl;
    return 0;
}
