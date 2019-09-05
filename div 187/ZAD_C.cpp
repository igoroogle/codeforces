#include <iostream>
using namespace std;
long long a[200010];
int main ()
    {
        int n,i;
        long long d,ans,k,ms;
        d = 0;
        ms = 0;
        cin >> n >> k;
        for (i=0;i<n;i++) cin >> a[i];
        for (i=0;i<n;i++)
            {
                ans = d - (n - 1 - i) * a[i] * (i - ms);
                if (ans < k)
                    {
                        ms++;
                        cout << i + 1 << endl;
                    }
                else d+=a[i] * (i - ms);
            }
        return 0;
    }
