#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int r = 0, b = 0, y = 0, g = 0, i;
    for (i = 0; i < s.length() - 3; ++i) {
        if ((s[i] != 'R') && (s[i + 1] != 'R') && (s[i + 2] != 'R') && (s[i + 3] != 'R')) {
            ++r;
        }

        if ((s[i] != 'B') && (s[i + 1] != 'B') && (s[i + 2] != 'B') && (s[i + 3] != 'B')) {
            ++b;
        }

        if ((s[i] != 'Y') && (s[i + 1] != 'Y') && (s[i + 2] != 'Y') && (s[i + 3] != 'Y')) {
            ++y;
        }

        if ((s[i] != 'G') && (s[i + 1] != 'G') && (s[i + 2] != 'G') && (s[i + 3] != 'G')) {
            ++g;
        }
    }

    cout << r << ' ' << b << ' ' << y << ' ' << g << endl;
 }
