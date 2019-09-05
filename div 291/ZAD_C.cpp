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
map <string,bool> pr;
string s,s1;
int main ()
    {
        int n,m,i,j;
        bool f;
        cin >> n >> m;
        for (i=0;i<n;i++)
            {
                cin >> s;
                pr[s] = 1;
            }
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
                                if (pr[s1])
                                    {
                                        printf("YES\n");
                                        f = 0;
                                        break;
                                    }
                            }
                        if (s[j] != 'b')
                            {
                                s1[j] = 'b';
                                if (pr[s1])
                                    {
                                        printf("YES\n");
                                        f = 0;
                                        break;
                                    }
                            }
                        if (s[j] != 'c')
                            {
                                s1[j] = 'c';
                                if (pr[s1])
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
