#include <iostream>
using namespace std;
long long a[100010];
int main ()
    {
        int n,m,i,t,v;
        long long uv,x;
        cin >> n >> m;
        for (i=0;i<n;i++) cin >> a[i];
        uv = 0;
        for (i=0;i<m;i++)
            {
                cin >> t;
                if (t == 1)
                    {
                        cin >> v >> x;
                        a[v-1] = x - uv;
                    }
                else if (t == 2)
                    {
                        cin >> x;
                        uv += x;
                    }
                else
                    {
                        cin >> v;
                        cout << a[v-1] + uv << endl;
                    }
            }
    }
