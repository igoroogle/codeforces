#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int i, n, k, kt, kk, x, ch = 0, nch = 0, sm;
    cin >> n >> k;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x % 2)
            nch++;
        else
            ch++;
    }
    sm = (ch * 2 + nch) % 2;
    if (k == n)
    {
        if (sm)
            cout << "Stannis\n";
        else
            cout << "Daenerys\n";
        return 0;
    }

    k = (n - k);
    if (k % 2)
    {
        kk = k / 2;
        kt = k - kk;
        if (sm)
        {
            if (((kk >= nch) && ((nch + kt + kt + kk - nch + kk - nch) % 2)) || ((kk >= ch) && ((ch + ch + kt + kk - ch) % 2)))
                cout << "Daenerys\n";
            else
                cout << "Stannis\n";
        }
        else
        {
            if (((kk >= nch) && (!((nch + kt + kt + kk - nch + kk - nch) % 2))) || ((kk >= ch) && (!((ch + ch + kt + kk - ch) % 2))))
                cout << "Daenerys\n";
            else
                cout << "Stannis\n";
        }
        return 0;
    }
    kk = (k - 1) / 2 + 1;
    kt = k - kk;
    if (sm)
    {
        if (((kk >= nch) && (!((nch + kt + kt + kk - nch + kk - nch) % 2))) || ((kk >= ch) && (!((ch + ch + kt + kk - ch) % 2))))
            cout << "Stannis\n";
        else
            cout << "Daenerys\n";
    }
    else
    {
        if (((kk >= nch) && ((nch + kt + kt + kk - nch + kk - nch) % 2)) || ((kk >= ch) && ((ch + ch + kt + kk - ch) % 2)))
            cout << "Stannis\n";
        else
            cout << "Daenerys\n";
    }
    return 0;
}
