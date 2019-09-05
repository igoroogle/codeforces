#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[50001];
int main()
{
    int n, m, i, j, k, vl;
    cin >> s;
    n = strlen(s);
    m = n >> 1;
    i = 1;
    while (i <= m)
    {
        k = i;
        vl = 0;
        for (j = i; j < n; j++)
        {
            if (s[j - i] != s[j])
                vl = -1;
            vl++;
            if (vl == i)
            {
                vl = 0;
                k -= i;
            }
            s[k] = s[j];
            k++;
        }

        n = k;
        m = (n >> 1);
        i++;
    }
    s[n] = '\0';
    printf("%s\n", s);
    return 0;
}
