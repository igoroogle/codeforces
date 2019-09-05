#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int d[4][201][201][201];
const int md = 1000000007;
int main ()
    {
        int t,r,p,i,j,k,a[201];
        scanf("%d",t);
        for (r=0;r<t;r++)
            {
                scanf("%d",n);
                for (i=0;i<n+n;i++) scanf("%d",a[i]);
                for (p=0;p<4;p++)
                    for (k=0;k<=n+n;k++)
                        for (i=0;i<=n+n;k++)
                            for (j=0;j<=n;j++) d[p][k][i][j] = 0;
                if ( (a[0] == 1) || (a[0] == 3) ) d[0][0][0][0] = 1;
                else if ( (a[0] == 2) || (a[0] == 3) ) d[3][0][0][0] = 1;
                for (p=1;p<n+n;p++)
                    {
                        for (i=0;i<n;i++)
                            for (j=0;j<n;j++)
                                {
                                    if (a[p] == 1)
                                        {
                                            d[0][p][i][j] = (d[0][p][i][j] + d[]) % md;
                                        }
                                }
                    }
            }
        return 0;
    }
