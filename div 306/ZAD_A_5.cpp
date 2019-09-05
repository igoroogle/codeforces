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
const double PI = 3.14159265358979311600;
const int inf = 1000100;
using namespace std;
string s;
int main ()
    {
        cin >> s;
        int a,b,len = s.length();
        if ( ( ( (s.find("BA",s.find("AB",0)+2) < len) && (s.find("BA",s.find("AB",0)+2) >= 0) ) || ( (s.find("AB",s.find("BA",0)+2) < len) && (s.find("AB",s.find("BA",0)+2) >= 0) ) ) && (s.find("AB",0) >=0)  && (s.find("BA",0) >=0) ) cout << "YES" << endl;
        else cout << "NO" << endl;
        cout << s.find("AB",0) << endl;
        cout << s.find("BA",0) << endl;
        return 0;
    }
