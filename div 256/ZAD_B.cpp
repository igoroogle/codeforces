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
const double EPS = 1E-10;
const ll inf = 2000000010;
using namespace std;
string s1,s2;
ll a[27],b[27];
int main ()
    {
        cin >> s1 >> s2;
        swap(s1,s2);
        ll i,n1 = s1.length(),n2 = s2.length(),l1 = 0,l2 = 0;
        for (i=0;i<27;i++)
            {
                a[i] = 0;
                b[i] = 0;
            }
        for (;;)
            {
                if (l1 >= n1)
                    {
                        cout << "automaton\n";
                        return 0;
                    }
                while ( (l2 < n2) && (s2[l2] != s1[l1]) ) l2++;
                if (l2 >= n2) break;
                l1++;
                l2++;
            }
        for (i=0;i<n1;i++) a[ll(s1[i]-'a')]++;
        for (i=0;i<n2;i++) b[ll(s2[i]-'a')]++;
        bool f = 1;
        for (i=0;i<27;i++)
            if ( min(a[i],b[i]) != max(a[i],b[i]) )
                {
                    f = 0;
                    break;
                }
        if (f)
            {
                cout << "array\n";
                return 0;
            }
        for (i=0;i<27;i++)
            if (a[i]>b[i])
                {
                    cout << "need tree\n";
                    return 0;
                }
        cout << "both\n";
        return 0;
    }
