#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[10010],b[10010];
int main ()
    {
        int i,j,n,l,t,s1,s2;
        scanf("%d",&t);
        for (i=0;i<t;i++)
            {
                scanf("%d%d",&n,&l);
                for (j=0;j<n;j++) scanf("%d",&a[j]);
                for (j=0;j<n;j++) scanf("%d",&b[j]);
                sort(a,a+n);
                sort(b,b+n);
                s1 = 0;
                s2 = 0;
                for (j=0;j<l;j++) s1+=a[j];
                for (j=n-1;j>=n-l;j--) s2+=b[j];
                if (s1 > s2) printf("YES\n");
                else printf("NO\n");
            }

        return 0;
    }
