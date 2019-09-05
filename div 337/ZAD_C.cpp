#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[613][613];
int n;
void rec(int l, int r, int num);
int main()
{
    cin >> n;
    n = (1 << n);
    rec(0, n - 1, 0);
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }

    return 0;
}

void rec(int l, int r, int num)
{
    if (num > n)
        return;

    if (l == r)
    {
        a[num][l] = '+';
        return;
    }

    if (l + 1 == r)
    {
        a[num][l] = '+';
        a[num][l + 1] = '*';
        a[num + 1][l] = '*';
        a[num + 1][l + 1] = '+';
        return;
    }


    int fl = l;
    int fr = (r - l + 1) / 2  + fl - 1;
    int sl = fr + 1;
    int sr = r;
    int i;
    rec(fl, fr, num);
    int j;
    for (i = sl; sl <= sr; i++)
        for (j = num; j <= num + (sr - sl); j++)
            a[i][j] = a[fl + i - sl][fl + j - num];

}
