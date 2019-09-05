#include <iostream>
using namespace std;
int main ()
    {
        int a [102],i,j,n,x,mx;
        cin >> n;
        a[0] = 0;
        for (i=1;i<=n; i++)
            {
                cin >> x;
                a[i] = a[i-1] + x;
            }
       a[n+1] = a[n];
       mx = 0;
       for (i=1;i<=n;i++)
            for (j=i;j<=n;j++)
                if (a[i-1] + a[n] - a[j] + j - i + 1 - a[j] + a[i-1] > mx)
                    mx = a[i-1] + a[n] - a[j] + j - i + 1 - a[j] + a[i-1];
       cout << mx;
    }
