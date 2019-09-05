#include <bits/stdc++.h>
using namespace std;

const int LEN = 1000100;
int n, ar[LEN], n1;
void vis(int n)
{
    if (n == 1)
    {

    }

    for (int i = 1; i <= n; i++)
    {
        n1++;
        ar[n1 - 1] = - i;
    }
}
void rec(int n)
{
    if (n == 1)
    {
        n1++;
        ar[n1 - 1] = 1;
        return;
    }
    rec(n - 1);
    if (n - 1 > 1)
        vis(n - 2);
    n1++;
    ar[n1 - 1] = n;
    if ( n - 2 >= 1)
        rec(n - 2);
}

int main()
{

    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
    cin >> n;
    rec(n);

    cout << n1 << endl;
    for (int i = 0; i < n1; i++)
        printf("%d ", ar[i]);

    return 0;
}
