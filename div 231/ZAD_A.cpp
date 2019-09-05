#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
    int n, i, a = 0, b = 0, c = 0;
    cin >> s;
    n = s.length();
    i = 0;
    while (s[i] != '+')
    {
        a++;
        i++;
    }
    i++;

    while (s[i] != '=')
    {
        b++;
        i++;
    }
    i++;

    while (i < n)
    {
        c++;
        i++;
    }

    if (a + b == c) cout << s << endl;
    else if ((c > 1) && (a + 1 + b == c - 1))
    {
        cout << '|' << s.substr(0, n - 1) << endl;
    }
    else if ((a > 1) && (a - 1 + b == c + 1))
    {
        cout << s.substr(1, n - 1) << '|' << endl;
    }
    else if ((b > 1) && (a  + b - 1 == c + 1))
    {
        cout << s.substr(0, a + b) << s.substr(a + b + 1, n - a - b) << '|' << endl;
    }
    else cout << "Impossible\n";
    return 0;
}
