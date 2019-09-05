#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[133];
int main()
{
    int n, i, kol = 0;
    bool f = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n++] = 0;
    a[n++] = 0;
    for (i = 0; i < n; i++)
    {
        if ((!f) && (a[i]))
        {
            f = 1;
            kol++;
        }
        else if ((f) && (!a[i]) && (!a[i + 1]))
            f = 0;
        else if (f)
            kol++;
    }
    cout << kol << endl;
    return 0;
}
