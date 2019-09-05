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
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
int a[110];
int main ()
    {
        int n,m,i,j,k = 0;
        cin >> n >> m;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (i=0;i<=110;i++)
            for (j=0;j<n;j++)
                {
                    if (a[j] > 0) k = j;
                    a[j]-=m;
                }
        cout << k + 1 << endl;
        return 0;
    }
