#include <bits/stdc++.h>
using namespace std;

const int LEN = 1000100;
int n, ar[LEN], n1;

void rec(int n);
void vis(int n);

int main()
{

    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
    cin >> n;
    for (int i = n; i > 0; i--)
        rec(i);

    cout << n1 << endl;
    for (int i = 0; i < n1; i++)
        printf("%d ", ar[i]);

    return 0;
}

void vis(int n)
{
    if (n == 1)
    {
        n1++;
        ar[n1 - 1] = -1;
        return;
    }

    rec(n - 1);
    n1++;
    ar[n1 - 1] = -n;
    vis(n - 1);
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
    n1++;
    ar[n1 - 1] = n;
    vis(n - 1);
}
