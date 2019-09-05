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
int main ()
    {
        int n,m,i,k = 0,k1,n1,m1;
        cin >> n >> m;
        for (i=0;i<=n;i++)
            {
                if (i > m / 2) continue;
                n1 = n - i;
                m1 = m - i*2;
                k1 = i;
                k1 +=min(m1,n1/2);
                if (k1 > k) k = k1;
            }
        cout << k << endl;
        return 0;
    }
