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

const int INF = 1E9 + 1;

int a[100010];

int main() {
    ios_base::sync_with_stdio(0);
    short int p = (1 << 15) - 2;
    for (int i = 0; i < 7; ++i) {
        cout << int(p) << endl;
        ++p;
    }
}
