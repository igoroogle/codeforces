#include <iostream>
using namespace std;
int main ()
    {
        int a[110],b[110],i,j,n,s;
        bool pr[110];
        cin >> n;
        for (i=0;i<n;i++) cin >> a[i] >> b[i];
        for (i=0;i<n;i++) pr[i] = 1;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if ( (i != j) && (a[j] == b[i]) ) pr[j] = 0;
        s = 0;
        for (i=0;i<n;i++)
            if (pr[i]) s++;
        cout << s;
    }
