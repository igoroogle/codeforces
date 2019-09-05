#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll n, k;
    cin >> n >> k;
    cout << n + k - n % k << endl;
    return 0;
}
