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

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        if (x == 1) {
            cout << "HARD\n";
            return 0;
        }
    }
    cout << "EASY\n";
}