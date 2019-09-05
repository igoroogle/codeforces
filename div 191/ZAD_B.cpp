#include <iostream>
using namespace std;
const int mxsize = 10000000;
bool b [mxsize+5];
const int dl = 2010;
int a[100010];
int main ()
    {
        int i,j,p,kol,n,x,mx;
        bool f;
        kol = 1;
        a[0] = 2;
        p = 3;
        while (kol < dl)
           {
                f = 1;
                for (j=kol-1; j >=0; j--)
                    if (!(p % a[j]))
                        {
                            f = 0;
                            break;
                        }
                if (f)
                    {
                        kol++;
                        a[kol-1] = p;
                    }
                p+=2;
           }
        cin >> n;
        //for (i=0; i < n; i++) cout << a[i] << " ";
        for (i=0;i<=mxsize;i++) b[i] = 0;
        p = 0;
        for (i=0;i<dl;i++)
           {
               if (p == n) break;
               for (j=i;j<dl;j++)
                    {
                        if (a[i]*a[j]<=mxsize)
                            {
                                b[a[i]*a[j]] = 1;
                                p++;
                            }
                        if (p == n) break;
                    }
           }
        p = 0;
        for (i=0;i<=mxsize;i++)
            if (b[i])
               {
                    p++;
                    a[p-1] = i;
               }
        for (i=0;i<n;i++) cout << a[i] << " ";
        return 0;
    }
