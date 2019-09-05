#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, ss, s1 = "", s2;
bool palin(string& s)
{
    int n = s.length();
    if (s == "")
        return 0;
    s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

int main()
{
    int n, i, j, p;
    cin >> s;
    n = s.length();

    for (i = 0; i < (1 << n); i++)
    {
        p = i;
        ss = "";
        for (j = 0; j < n; j++)
        {
            if (p % 2)
                ss += s[j];
            p /= 2;
        }
        if ((palin(ss)) && (ss > s1))
                s1 = ss;
    }

    cout << s1 << endl;
    return 0;
}
