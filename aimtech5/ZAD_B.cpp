#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const int DL = 1000;
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    cout << '8';
    for (int i = 1; i <= DL; ++i) {
        cout << "09";
    }
    cout << '\n';
    cout << '1';
    for (int i = 1; i < DL; ++i) {
        cout << "90";
    }
    cout << "91\n";
}
