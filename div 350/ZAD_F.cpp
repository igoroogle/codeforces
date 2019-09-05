#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
int st[500010], prv[500010], nex[500010], pr[500010];
bool col[500010];
char s[500010], t[500010];
int toNext(int n);
int toPrev(int n);
int main()
{
    int kl = 0, n, m, p, i, l, r, tx;
    cin >> n >> m >> p;
    scanf("%s", &s);
    scanf("%s", &t);
    for (i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st[kl++] = i;
        else
        {
            pr[st[kl - 1]] = i;
            pr[i] = st[kl - 1];
            kl--;
        }
        prv[i] = i - 1;
        nex[i] = i + 1;
    }

    nex[n - 1] = -1;
    p--;
    /*for (i = 0; i < n; i++)
        cout << i << ' ' << pr[i] << endl;*/
    //return 0;
    for (i = 0; i < m; i++)
    {
        //cout << i << ' ' << p << endl;
        if (t[i] == 'R')
        {
            p = toNext(nex[p]);
            continue;
        }

        if (t[i] == 'L')
        {
            p = toPrev(prv[p]);
            continue;
        }

        l = p;
        r = pr[p];
        if (l > r)
            swap(l, r);
        //cout << "lr " << l << ' ' << r << endl;
        p = l;
        while (p <= r)
        {
            //cout << p << endl;
            col[p] = 1;
            tx = toNext(p);
            if (tx != -1)
            {
                p = tx;
                continue;
            }

            p = toPrev(p);
            break;
        }
    }

    for (i = 0; i < n; i++)
        if (!col[i])
            printf("%c", s[i]);

    return 0;
}

int toNext(int n)
{
    if (n == -1)
        return -1;
    if (!col[n])
        return n;
    nex[n] = toNext(nex[n]);
    return nex[n];
}

int toPrev(int n)
{
    if (n == -1)
        return -1;
    if (!col[n])
        return n;
    prv[n] = toPrev(prv[n]);
    return prv[n];
}
