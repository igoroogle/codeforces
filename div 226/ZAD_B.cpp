#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef short int shi;
string s;
shi a[5000][5000], n;
bool rec(shi l, shi r);
int main()
{
    shi i, j, mx = 0, c;
    int sum = 0;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            a[i][j] = -1;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            if (rec(i, j))
                sum++;
    cout << sum << endl;
    return 0;
}

bool rec(shi l, shi r)
{
    if ((l < 0) || (l >= n) || (r < 0) || (r >= n) || (r < l))
        return 0;
    if (a[l][r] != -1)
        return a[l][r];
    if (r - l + 1 < 4)
    {
        a[l][r] = 0;
        return 0;
    }
    if (r - l + 1 == 4)
    {
        if (s.substr(l, 4) == "bear")
            a[l][r] = 1;
        else
            a[l][r] = 0;
        return a[l][r];
    }
    if (rec(l + 1, r) || rec(l, r  - 1))
        a[l][r] = 1;
    else
        a[l][r] = 0;
    return bool(a[l][r]);
}
