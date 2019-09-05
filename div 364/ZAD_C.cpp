#include<bits/stdc++.h>
#define x firsr
#define y second
#define mp make pair
#define pb push_back
using namespace std;
typedef long long ll;
int toint(char c);
int kl[103];
char a[100010];
int main()
{
    int n, i, kol = 0, mn, l, ss = 0;
    cin >> n;
    mn = n;
    scanf("%s", &a);
    l = 0;
    for (i = 0; i < n; i++)
        kl[toint(a[i])]++;

    for (i = 0; i < 103; i++)
        if (kl[i])
        {
            kl[i] = 0;
            ss++;
        }

    for (i = 0; i < n; i++)
    {
        kl[toint(a[i])]++;
        if (kl[toint(a[i])] == 1)
            kol++;

        while ((l < i) && (kol == ss) && (kl[toint(a[l])] > 1))
        {
            kl[toint(a[l])]--;
            l++;
        }

        if (kol == ss)
            mn = min(mn, i - l + 1);
    }

    cout << mn << endl;
    return 0;
}

int toint(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return (int(c) - int('A'));
    return (int(c) - int('a') + 26);
}
