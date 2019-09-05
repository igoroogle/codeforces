#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mas[2010], ans1[2000100], ans2[2000100], a[2010], b[2010];
int main()
{
    int i, j, kol = 0, n, ind;
    ll sum = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            a[i]--;
        }
    for (i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            b[i]--;
            mas[b[i]] = i;
        }
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < n; j++)
            if (a[j] == b[i])
            {
                ind = j;
                break;
            }
        j = ind + 1;
        while (ind < i)
        {
            if (mas[a[j]] <= ind)
            {
                ans1[kol] = ind + 1;
                ans2[kol++] = j + 1;
                sum += ll(abs(ind - j));
                swap(a[ind], a[j]);
                ind = j;
            }
            j++;
        }
    }
    cout << sum << endl;
    cout << kol << endl;
    for (i = 0; i < kol; i++)
        printf("%d %d\n", ans1[i], ans2[i]);
    return 0;
}
