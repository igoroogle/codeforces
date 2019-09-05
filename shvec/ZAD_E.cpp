#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2000000010;
int as[100010], bs[100010], cs[100010], mas[100010];
int main()
{
    int a = 0, b = 0, c = 0, n, a1, i;
    as[0] = -INF;
    bs[0] = -INF;
    cs[0] = -INF;
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%d", &mas[i]);
    for (i = 1; i <= n; i++)
    {
        as[i] = as[i - 1];
        bs[i] = bs[i - 1];
        cs[i] = cs[i - 1];
        if (mas[i] == 0)
        {
            as[i] = -INF;
            bs[i] = -INF;
            cs[i] = -INF;
            continue;
        }
        if (mas[i] > as[i])
        {
            cs[i] = bs[i];
            bs[i] = as[i];
            as[i] = mas[i];
        }
        else if (mas[i] > bs[i])
        {
            cs[i] = bs[i];
            bs[i] = mas[i];
        }
        else if (mas[i] > cs[i])
            cs[i] = mas[i];
    }
    for (i = n - 1; i >= 1; i--)
    if (mas[i] != 0)
    {
        as[i] = max(as[i + 1], as[i]);
        bs[i] = max(bs[i + 1], bs[i]);
        cs[i] = max(cs[i + 1], cs[i]);
    }
    for (i = 1; i <= n; i++)
    {
        a1 = mas[i];
        if (a1 > 0)
        {
            if ((a == 0) && (a1 == as[i]))
            {
                a++;
                printf("pushStack\n");
            }
            else if ((b == 0) && (a1 == bs[i]))
            {
                b++;
                printf("pushQueue\n");
            }
            else if ((c == 0) && (a1 == cs[i]))
            {
                c++;
                printf("pushFront\n");
            }
            else
                printf("pushBack\n");
        }
        else
        {
            printf("%d", a + b + c);
            if (a > 0)
                printf(" popStack");
            if (b > 0)
                printf(" popQueue");
            if (c > 0)
                printf(" popFront");
            printf("\n");
            a = 0;
            b = 0;
            c = 0;
        }
    }
    return 0;
}
