#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b);
int a[110];
int main()
{
    int n, i, nd;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    nd = a[0];
    for (i = 1; i < n; i++)
        nd = gcd(nd, a[i]);
    if ((a[n - 1] / nd - n) % 2)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
