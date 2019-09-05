#include <cstdio>
int a[502],d[502][502];
int main()
    {
        int n,m,b,md,i,j,k,s;
        for (i=0;i<502;i++)
            for (j=0;j<502;j++) d[i][j] = 0;
        d[0][0] = 1 % md;
        scanf("%d%d%d%d",&n,&m,&b,&md);
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (k=0;k<n;k++)
            for (i=1;i<=m;i++)
                for (j=0;j<=b;j++)
                        if (j-a[k]>=0)
                            {
                                d[i][j]+=d[i-1][j-a[k]];
                                if (d[i][j] >= md) d[i][j]-=md;
                            }
        s = 0;
        for (i=0;i<=b;i++)
            {
                s+=d[m][i];
                if (s>=md) s-=md;
            }
        printf("%d",s);
        return 0;
    }
