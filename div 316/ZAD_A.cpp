#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[110];
int main()
{
    int n, m, i, j, mn , mn2, x;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> mn;
        mn2 = 0;
        for (j = 1; j < n; j++)
        {
            cin >> x;
            if (x > mn)
            {
                mn = x;
                mn2 = j;
            }
        }
        a[mn2]++;
    }
    mn = a[0];
    mn2 = 0;
    for (i = 0; i < n; i++)
        if (a[i] > mn)
        {
            mn = a[i];
            mn2 = i;
        }
    cout << mn2 + 1 << endl;
    return 0;
}
