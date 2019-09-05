#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, p = 0, t = 0;
    cin >> n;
    for (i = 0; i < (1 << n); i++)
    {
        j = i;
        p = 0;
        while (j > 0)
        {
            if (j % 2)
                p++;
            j /= 2;
        }
        if (p == n / 2)
            t++;
    }
    cout << t << endl;
}
