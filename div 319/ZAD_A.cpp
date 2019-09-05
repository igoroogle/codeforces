#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1010], b[1010], cnt = 0, cnt2 = 0;
int main()
{
    int n, i, j;
    bool f;
    cin >> n;
    j = n;
    for (i = 2; i <= n; i++)
    {
        f = 1;
        for (j = 2; j < i; j++)
            if (i % j == 0)
            {
                f = 0;
                break;
            }
        if (f)
        {
            cnt++;
            a[cnt - 1] = i;
        }
    }


    for (i = 0; i < cnt; i++)
        for (j = a[i]; j <= n; j = j * a[i])
        {
            cnt2++;
            b[cnt2 - 1] = j;
        }
    cout << cnt2 << endl;
   for (i = 0; i < cnt2; i++)
        printf("%d ", b[i]);
    return 0;
}
