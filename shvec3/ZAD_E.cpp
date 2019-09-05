#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, a ="", b = "", c = "";
int main()
{
    int n, ind = 0;
    cin >> s;
    n = s.length();
    if (s.substr(0, 3) == "ftp")
    {
        a = "ftp";
        ind = 3;
    }
    else
    {
        a = "http";
        ind = 4;
    }

    b = s[ind];
    ind++;
    for(;;)
    {
        if (s.substr(ind, 2) != "ru")
            b += s[ind];
        else
        {
            ind += 2;
            break;
        }
        ind++;
    }

    while (ind < n)
        {
            c += s[ind];
            ind++;
        }
    if (c == "")
        cout << a + "://" + b + ".ru\n";
    else
        cout << a + "://" + b + ".ru/" + c << endl;
    return 0;
}
