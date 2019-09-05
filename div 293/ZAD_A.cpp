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
string a,b;
int main ()
    {
        cin >> a >> b;
        int i,k = -1;
        for (i=a.length()-1;i>=0;i--)
            {
                if (a[i] != 'z' )
                    {
                        k = i;
                        break;
                    }
            }
        if (k == -1)
            {
                cout << "No such string" << endl;
                return 0;
            }
        a[k] = a[k]+1;
        for (i=k+1;i<a.length();i++) a[i] = 'a';
        if (a == b) cout << "No such string" << endl;
        else cout << a << endl;
        return 0;
    }
