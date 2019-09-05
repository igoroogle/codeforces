#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    int les = 0, mor = 0, zer = 0, n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if (x < 0) {
            ++les;
        } else if (x > 0) {
            ++mor;
        } else {
            ++zer;
        }
    }

    if (mor >= les + zer) {
        cout << "1\n";
    } else if (les >= mor + zer) {
        cout << "-1\n";
    } else {
        cout << "0\n";
    }
}
