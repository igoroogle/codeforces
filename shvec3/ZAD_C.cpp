#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int ans[33][12][3];
const int mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isnum(char c)
{
    return ((c >= '0') && (c <= '9'));
}
int main()
{
    int a, b, c, n, i, j, k, mx = 0;
    cin >> s;
    n = s.length();
    for (i = 0; i < n - 9; i++)
        if ((isnum(s[i])) && (isnum(s[i + 1])) && (isnum(s[i + 3]))
        && (isnum(s[i + 4])) && (isnum(s[i + 6])) && (isnum(s[i + 7]))
        && (isnum(s[i + 8])) && (isnum(s[i + 9])) && (s[i + 2] == '-')
        && (s[i + 5] == '-'))
        {
            a = int(s[i] - '0') * 10 + int(s[i + 1] - '0');
            b = int(s[i + 3] - '0') * 10 + int(s[i + 4] - '0');
            c =  int(s[i + 6] - '0');
            c = c * 10 + int(s[i + 7] - '0');
            c = c * 10 + int(s[i + 8] - '0');
            c = c * 10 + int(s[i + 9] - '0');
            if ((a > 0) && (a < 33) && (b > 0) && (b < 13) && (c > 2012) && (c < 2016))
                ans[a - 1][b - 1][c - 2013]++;
        }

    for (i = 0; i < 33; i++)
        for (j = 0; j < 12; j++)
            for (k = 0; k < 3; k++)
                if ((i < mes[j]) && (mx < ans[i][j][k]))
                {
                    mx = ans[i][j][k];
                    a = i;
                    b = j;
                    c = k;
                }
    a++;
    b++;
    c += 2013;
    printf("%d%d-%d%d-%d\n", a / 10, a % 10, b / 10, b % 10, c);
    return 0;
}
