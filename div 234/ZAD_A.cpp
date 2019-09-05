#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 147;
string s;
int a[DL], b[DL];
int main()
{
    int n, i, j, p, m, k, nl, t, u;
    bool f;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        m = s.length();
        k = 0;
        nl = 0;
        for (j = 1; j <= 12; j++)
            for (p = 1; p <= 12; p++)
                if (j * p == 12)
                {
                   nl = 0;
                   f = 0;
                   for (u = 0; u < p; u++)
                        {
                            nl = 0;
                            for (t = u; t < 12; t+=p)
                                if (s[t] == 'O') nl++;
                            if (nl == 0)
                            {
                                f = 1;
                                break;
                            }
                        }
                    if (f)
                    {
                        k++;
                        a[k - 1] = j;
                        b[k - 1] = p;
                    }
                }
        printf("%d", k);
        if (k > 0) printf(" ");
        for (j = 0; j < k - 1; j++) printf("%dx%d ", a[j], b[j]);
        if (k > 0)
            printf("%dx%d", a[k - 1], b[k - 1]);
        printf("\n");
    }
    return 0;
}
