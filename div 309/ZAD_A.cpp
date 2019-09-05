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
string s;
int main ()
    {
        cin >> s;
        int ss = 0,i,j,n = s.length();
        for (i=1;i<n;i++)
            for (j=0;j<26;j++)
                if (pr[s.substr(0,i)+char(j+'a')+s.substr(i,n-i)] == 0)
                    {
                        pr[s.substr(0,i)+char(j+'a')+s.substr(i,n-i)]++;
                        ss++;
                    }
        for (j=0;j<26;j++)
                if (pr[s+char(j+'a')] == 0)
                    {
                        pr[s+char(j+'a')]++;
                        ss++;
                    }
        for (j=0;j<26;j++)
                if (pr[char(j+'a')+s] == 0)
                    {
                        pr[char(j+'a')+s]++;
                        ss++;
                    }
        cout << ss << endl;
        return 0;
    }
