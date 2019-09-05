#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
string s1,s2,s3 = "";
int main ()
    {
        bool f = 1;
        int i;
        cin >> s1 >> s2;
        for (i=0;i<s1.length();i++)
            {
                if (s1[i] == s2[i]) s3+=s1[i];
                else
                    {
                        if (f)
                            {
                                f = 0;
                                s3+=s1[i];
                            }
                        else
                            {
                                f = 1;
                                s3+=s2[i];
                            }
                    }
            }
        if (!f) cout << "impossible" << endl;
        else cout << s3 << endl;
        return 0;
    }
