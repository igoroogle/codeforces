#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <map>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
const ll md = 1000000007;
using namespace std;
int a[1010];
int main ()
    {
        int n,i,j;
        bool f = 0;
        cin >> n;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (j=0;j<3010;j++)
            {
                f = 1;
                for (i=0;i<n;i++)
                    if (i != a[i])
                        {
                            f = 0;
                            break;
                        }
                if (f) break;

                for (i=0;i<n;i++)
                    {
                        if (i%2) a[i] = (a[i] + n - 1) % n;
                        else a[i] = (a[i] + 1) % n;
                    }
            }
        if (f) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
