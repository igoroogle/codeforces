#include <iostream>
#include <algorithm>
using namespace std;
int main ()
    {
        int n,i,k,p,x,y,s,med,a[1010];
        cin >> n >> k >> p >> y;
        for(i=0;i<k;i++) cin >> a[i];
        sort(a,a+k);
        med = (n+1)/2;
        if (k < med) a[med-1] = y;
        if ( (k<med) && (k>0) % (a[k-1]>a[med-1]) ) a[med-1] = a[k-1];
        for (i=k;i<med-1;i++) a[i] = 1;
        for (i=med;i<n;i++) a[i] = a[i-1];
        s = 0;
        for (i=0;i<n;i++) s += a[i];
        /*if ( (s>x) || (a[med-1] < y) )
            {
                cout << -1;
                return 0;
            }*/
        for(i=0;i<n;i++) cout << a[i] << " ";
        return 0;
    }
