#include <bits/stdc++.h>
using namespace std;

const int LEN = 1000100;
int n, ar[LEN], n1;

void rec(int n, bool f)
{
    if (f)
    {
        if (n < 1)
            return;
        if (n == 1)
        {
            n1++;
            ar[n1 - 1] = 1;
            return;
        }
        rec(n - 1, 1);
        rec(n - 2, 0);
        n1++;
        ar[n1 - 1] = n;
        rec(n - 2, 1);
    }
    else
    {
        if (n < 1)
            return;
        if (n == 1)
        {
            n1++;
            ar[n1 - 1] = -1;
            return;
        }
        rec(n - 2, 0);
        n1++;
        ar[n1 - 1] = - n;
        rec(n - 2, 1);
        rec(n - 1, 0);
    }
}

int main()
{

    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
    cin >> n;
    rec(n, 1);
    cout << n1 << endl;
    for (int i = 0; i < n1; i++)
        printf("%d ", ar[i]);

    return 0;
}
