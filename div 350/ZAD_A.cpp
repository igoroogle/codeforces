#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n  < 3)
        cout << 0 << ' ' << n << endl;
    else
    {
        if (n % 7 == 6)
            cout << n / 7 * 2 + 1 << ' ';
        else
            cout << n / 7 * 2 << ' ';
        n -= 2;
        if (n % 7 == 6)
            cout << n / 7 * 2 + 3 << ' ';
        else
            cout << n / 7 * 2 + 2 << ' ';
    }
    return 0;
}
