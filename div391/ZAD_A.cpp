#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const string w = "Bulbasaur";
int a[1001];
string s;
int main() {
    ios_base::sync_with_stdio(0);
    int i, mn = 1E9;
    cin >> s;
    for (i = 0; i < s.length(); ++i) {
        ++a[s[i]];
    }

    for (i = 0; i < w.length(); ++i) {
        mn = min(mn, a[w[i]]);
    }

    cout << mn << endl;
}
