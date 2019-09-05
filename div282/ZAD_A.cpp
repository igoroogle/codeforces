#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
    int n, i, k, t = -1;
    cin >> n >> k;
    cin >> s;
    for (i = 0; i < n; ++i) {
        if ((s[i] == 'G') || (s[i] == 'T')) {
            t = i;
            break;
        }


    }

    for (i = t + k; i < n; ++i) {
        if ((s[i] == 'G') || (s[i] == 'T')) {
            cout << "YES\n";
        return 0;
        }

        if (s[i] == '#') {
            break;
        }
    }

    cout << "NO\n";
    return 0;
}
