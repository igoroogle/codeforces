#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d1, d2, d3, ans;
    cin >> d1 >> d2 >> d3;
    ans = d1 + d1 + d2 + d2;
    ans = min(d1 + d1 + d3 + d3, ans);
    ans = min(d2 + d2 + d3 + d3, ans);
    ans = min(d1 + d2 + d3, ans);
    cout << ans << endl;
    return 0;
}
