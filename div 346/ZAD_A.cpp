#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    a--;
    //b--;
    cout << (a + n * 1000 + b) % n  + ll(1) << endl;
    return 0;
}
