#include <iostream>
using namespace std;
int main ()
    {
        int n,i,x,y,sk;
        char a[1010],b[1010];
        cin >> n;
        for(i=0;i<n;i++) cin >> a[i];
        for(i=0;i<n;i++) cin >> b[i];
        sk = 0;
        for (i=0;i<n;i++)
            {
                x = int(a[i]) - 48;
                y = int(b[i]) - 48;
                if (x>y) swap(x,y);
                sk += min(y-x,10-y+x);
            }
        cout << sk;
        return 0;
    }
