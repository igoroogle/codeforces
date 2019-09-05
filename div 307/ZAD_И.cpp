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
int a[2010];
int main ()
    {
        int n,i,j,k;
        cin >> n;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (i=0;i<n;i++)
            {
                k = 1;
                for (j=0;j<n;j++)
                    if (a[j] > a[i]) k++;
                printf("%d ",k);
            }
        return 0;
    }
