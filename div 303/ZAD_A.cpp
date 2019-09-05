#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
int main ()
    {
        int a[110][110],h[110],k = 0,i,j,n;
        cin >> n;
        for (i=0;i<n;i++)
           for (j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for (i=0;i<n;i++)
            {
                for (j=0;j<=n;j++)
                {
                    if (j == n)
                        {
                            k++;
                            h[k-1] = i;
                            break;
                        }
                    if ( (a[i][j] == 1) || (a[i][j] == 3) ) break;
                }
            }
        cout << k << endl;
        for (i=0;i<k;i++) printf("%d ",h[i]+1);
        return 0;
    }
