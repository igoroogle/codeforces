#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mx[33][33], mn[33][33];
int month(string& s);
int week(string& s);
string s, s1;
int main()
{
    freopen("holidays.in", "r", stdin);
    freopen("holidays.out", "w", stdout);
    int n, i, j, fm, nm, dn, ms;
    for (i = 0; i < 33; i++)
        for (j = 0; j < 33; j++)
            mn[i][j] = -1;
    cin >> n;
    cin >> s;
    fm = week(s);
    cin >> s;
    if (s == "yes")
        mes[1] = 29;
    nm = 0;
    ms = 0;
    dn = fm;
    while (ms < 12)
    {
        if (mn[dn][ms] == -1)
            mn[dn][ms] = nm;
        mx[dn][ms] = nm;
        if (nm + 1 < mes[ms])
            nm++;
        else
        {
            nm = 0;
            ms++;
        }
        dn = (dn + 1) % 7;
    }
    for (i = 0; i < n; i++)
    {
        cin >> s1;
        cin >> s;
        dn = week(s);
        cin >> s;
        cin >> s;
        ms = month(s);
        if (s1 == "first")
            printf("%d\n", mn[dn][ms] + 1);
        else
            printf("%d\n", mx[dn][ms] + 1);
    }
    return 0;
}

int month(string& s)
{
    if (s == "january")
        return 0;
    if (s == "february")
        return 1;
    if (s == "march")
        return 2;
    if (s == "april")
        return 3;
    if (s == "may")
        return 4;
    if (s == "june")
        return 5;
    if (s == "july")
        return 6;
    if (s == "august")
        return 7;
    if (s == "september")
        return 8;
    if (s == "october")
        return 9;
    if (s == "november")
        return 10;
    if (s == "december")
        return 11;
}

int week(string& s)
{
    if (s == "monday")
        return 0;
    if (s == "tuesday")
        return 1;
    if (s == "wednesday")
        return 2;
    if (s == "thursday")
        return 3;
    if (s == "friday")
        return 4;
    if (s == "saturday")
        return 5;
    if (s == "sunday")
        return 6;
}
