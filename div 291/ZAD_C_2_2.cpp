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
string a[600010],s,s1;
int n;
bool binp(string&);
int main ()
    {
        int m,i,j;
        bool f;
        cin >> n >> m;
        for (i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        for (i=0;i<m;i++)
            {
                cin >> s;
                s1 = s;
                f = 1;
                for (j=0;j<s.length();j++)
                    {
                        if (s[j] != 'a')
                            {
                                s1[j] = 'a';
                                if (binp(s1))
                                    {
                                        printf("YES\n");
                                        f = 0;
                                        break;
                                    }
                            }
                        if (s[j] != 'b')
                            {
                                s1[j] = 'b';
                                if (binp(s1) )
                                    {
                                        printf("YES\n");
                                        f = 0;
                                        break;
                                    }
                            }
                        if (s[j] != 'c')
                            {
                                s1[j] = 'c';
                                if (binp(s1))
                                    {
                                        printf("YES\n");
                                        f = 0;
                                        break;
                                    }
                            }
                        s1[j] = s[j];
                    }
                if (f) printf("NO\n");
            }
        return 0;
    }
bool binp (string& s)
    {
        int l,r,m,i;
        l = 0;
        r = n-1;
        while (l < r)
            {
               m = (l+r) / 2;
               if (a[m] < s) l = m+1;
               else r = m;
            }
        return s == a[l];
    }
