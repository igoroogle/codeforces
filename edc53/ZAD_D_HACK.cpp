#include<bits/stdc++.h>
using namespace std;
long long dap,n,t,a[200010],sum,cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    int i;
    cin >> n >> t;
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    while(1)
    {
        sum=0; cnt=0;
        for(i=1;i<=n;i++)
        {
            if(sum+a[i]<=t){sum+=a[i]; cnt++;}
        }
        if(sum==0) break;
        dap+=(t/sum)*cnt;
        t%=sum;
    }
    cout << dap;
    return 0;
}
