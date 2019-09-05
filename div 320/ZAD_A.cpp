#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    long double a, b;
    cin >> a >> b;
    if (a >= b)
        cout << fixed << setprecision(13) << a / b << endl;
    else cout << -1 << endl;
    return 0;
}
