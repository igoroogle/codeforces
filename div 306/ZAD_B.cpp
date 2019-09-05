#include <iostream>
using namespace std;
int main ()
    {
        int n,l,r,x,i,j,p,a[21],s,mn,mx,kol = 0;
        cin >> n >> l >> r >> x;
        for (i=0;i<n;i++) cin >> a[i];
        for (i=0;i<(1 << n);i++)
            {
                s = 0;
                mn = 1000000010;
                mx = - 1000000010;
                p = i;
                for (j=0;j<n;j++)
                    {
                        if (p%2)
                            {
                                if (a[j] < mn) mn = a[j];
                                if (a[j] > mx) mx = a[j];
                                s+=a[j];
                            }
                        p/=2;
                    }
                if ( (s >= l) && (s<=r) && (mx - mn >= x)) kol++;
            }
        cout << kol << endl;
        return 0;
    }
