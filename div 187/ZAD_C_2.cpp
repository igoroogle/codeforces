#include <cstdio>
using namespace std;
int a[200010];
long long lg(int);
int main ()
    {
        int n,i;
        long long d,ans,k,ms;
        d = 0;
        ms = 0;
        scanf("%d %I64d",&n,&k);
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (i=0;i<n;i++)
            {
                ans = d - (n - 1 - i) * lg(a[i]) * (i - ms);
                if (ans < k)
                    {
                        ms++;
                        printf("%d \n",i+1);
                    }
                else d+=lg(a[i]) * (i - ms);
            }
        return 0;//ll
    }
long long lg (int x)
    {
        return x;
    }
