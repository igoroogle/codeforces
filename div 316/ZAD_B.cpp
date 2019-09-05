#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 100000000000;
int main()
{
    ll n, m, val;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (m == 1) val = 2;
    else if (m == n) val = n - 1;
    else if (m - 1 >= n - m) val = m - 1;
    else val = m + 1;
    cout << val << endl;
    return 0;
}
