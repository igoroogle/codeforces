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
using namespace std;
map <string,int> pr;
string a[110];
int main ()
    {
        int n,i,k = 1,mx = 1;
        cin >> n;
        for (i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        a[n] = '-';
        for (i=1;i<=n;i++)
            {
                if (a[i] == a[i-1]) k++;
                else
                    {
                        if (k > mx) mx = k;
                        k = 1;
                    }
            }
        cout << mx << endl;
        return 0;
    }
