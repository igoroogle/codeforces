#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[100010];
int main()
{
    int n, sum = 0, mx, sum1 = 0, i, k;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cin >> s;
    k = s.length();
    for (i = k; i < n; i++)
        s += '0';
    reverse(a, a + n);
    reverse(s.begin(), s.end());
    for (i = 0; i < n; i++)
        sum += a[i];
    mx = 0;
    for (i = 0; i < n; i++)
    {
        sum -= a[i];
        if (s[i] == '1')
        {
            mx = max(mx, sum + sum1);
            sum1 += a[i];
        }
    }
    mx = max(sum1, mx);
    cout << mx << endl;
    return 0;
}
