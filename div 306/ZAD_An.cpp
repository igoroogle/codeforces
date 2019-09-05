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
string s;
int main ()
    {
        cin >> s;
        ll a,b;
        a = s.find("AB",0);
        b = s.find("BA",0);
        if ( ( (a >=0) && (a < s.length()-2) && (s.find("BA",a+2) >= 0) && (s.find("BA",a+2) < s.length()) )
        || ( (b >=0) && (b < s.length()-2) && (s.find("AB",b+2) >= 0) && (s.find("AB",b+2) < s.length()) ) ) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
