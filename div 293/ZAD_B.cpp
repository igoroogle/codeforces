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
string s,t;
int a1[27],a2[27],b1[27],b2[27];
int main ()
    {
        cin >> s >> t;
        int i;
        for (i=0;i<27;i++)
            {
                a1[i] = 0;
                a2[i] = 0;
                b1[i] = 0;
                b2[i] = 0;
            }
        for (i=0;i<s.length();i++)
            {
                if ( (s[i] >='a') && (s[i] <= 'z') ) a1[int(s[i]-'a')]++;
                else b1[int(s[i]-'A')]++;
            }
        for (i=0;i<t.length();i++)
            {
                if ( (t[i] >='a') && (t[i] <= 'z') ) a2[int(t[i]-'a')]++;
                else b2[int(t[i]-'A')]++;
            }
        int u = 0,op = 0;
        for (i=0;i<27;i++)
            {
                if (a1[i] > a2[i])
                    {
                        u+=a2[i];
                        a1[i]-=a2[i];
                        a2[i] = 0;
                    }
                else
                    {
                        u+=a1[i];
                        a2[i]-=a1[i];
                        a1[i] = 0;
                    }
                if (b1[i] > b2[i])
                    {
                        u+=b2[i];
                        b1[i]-=b2[i];
                        b2[i] = 0;
                    }
                else
                    {
                        u+=b1[i];
                        b2[i]-=b1[i];
                        b1[i] = 0;
                    }
            }
        for (i=0;i<27;i++)
            {
                a1[i]+=b1[i];
                a2[i]+=b2[i];
            }
        for (i=0;i<27;i++)
            {
                if (a1[i] > a2[i])
                    {
                        op+=a2[i];
                        a1[i]-=a2[i];
                        a2[i] = 0;
                    }
                else
                    {
                        op+=a1[i];
                        a2[i]-=a1[i];
                        a1[i] = 0;
                    }
            }
        cout << u << ' ' << op << endl;
        return 0;
    }
