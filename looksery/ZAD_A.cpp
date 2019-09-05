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
const ld EPS = 1E-12;
using namespace std;
int main ()
    {
        int n,m,i,j,s = 0;
        char a[110][110];
        cin >> n >> m;
        for (i=0;i<n;i++)
            for (j=0;j<m;j++) cin >> a[i][j];
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                if  ( (i+1 < n) && (j+1 < m)  && ((a[i][j] == 'f') || (a[i+1][j] == 'f') || (a[i+1][j+1] == 'f') || (a[i][j+1] == 'f')) && ((a[i][j] == 'a') || (a[i+1][j] == 'a') || (a[i+1][j+1] == 'a') || (a[i][j+1] == 'a')) && ((a[i][j] == 'c') || (a[i+1][j] == 'c') || (a[i+1][j+1] == 'c') || (a[i][j+1] == 'c')) && ((a[i][j] == 'e') || (a[i+1][j] == 'e') || (a[i+1][j+1] == 'e') || (a[i][j+1] == 'e')) )
                   s++;
        cout << s << endl;
        return 0;
    }
