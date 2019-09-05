#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll getnum(char c);
char getchar(ll c);
ll getcoun(string s, ll radix);
string getsix(ll n, ll radix);
int main()
{
    ll n, radix, sum = 0, i, j, st;
    cin >> n >> radix;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        sum += getcoun(s, radix);
    }
    cout << getsix(sum, radix) << endl;
    return 0;
}

ll getnum(char c)
{
    if ((c >= '0') && (c <= '9'))
        return ll(c - '0');
    return ll(c - 'A' + 10);
}

char getchar(ll c)
{
    if (c < 10)
        return char('0' + c);
    return char(c - 10 + 'A');
}

ll getcoun(string s, ll radix)
{
    ll i, j = 1, ans = 0;
    while ((s.length() > 0) && (s[0] == '0'))
        s.erase(0, 1);
    if (s.length() == 0)
        return 0;
    for (i = s.length() - 1; i >= 0; i--)
    {
        ans += getnum(s[i]) * j;
        j *= radix;
    }
    return ans;
}

string getsix(ll n, ll radix)
{
    string s = "";
    ll i;
    while (n > 0)
    {
        s = getchar(n % radix) + s;
        n /= radix;
    }

    if (s == "")
        s = "0";
    return s;
}
