#include<bits/stdc++.h>
using namespace std;
const int DL = 800010;
const int INF = 2E9;
string s;
int t[DL], a[27], lt[DL], rt[DL];
void update(int l, int r, int v, int ind, int x);
int get(int l, int r, int v, int l1, int r1);
int m;
int main() {

    int k, kl = 0, i, l = 0, n;

    for(i = 0; i < DL; i++)
        t[i] = INF;

    cin >> k >> s;
    n = s.length();
    for (i = 0; i < s.length(); i++)
    {
        a[int(s[i] - 'a')]++;
        if (a[int(s[i] - 'a')] == 1)
            kl++;

        while (k < kl)
        {
            a[int(s[l] - 'a')]--;
            if(a[int(s[l] - 'a')] == 0)
                kl--;
            l++;
        }

        lt[i + 1] = -1;
        if (kl == k)
            lt[i + 1] = l;

        //cout << "l " << l << endl;
    }

    for (i = 0; i < 27; i++)
        a[i] = 0;

    l = 0;
    kl = 0;

    for (i = 0; i < s.length(); i++)
    {
        a[int(s[i] - 'a')]++;
        if (a[int(s[i] - 'a')] == 1)
            kl++;

        while ((a[int(s[l] - 'a')] > 1) || (k < kl))
        {
            a[int(s[l] - 'a')]--;
            if(a[int(s[l] - 'a')] == 0)
                kl--;
            l++;
        }

        rt[i + 1] = -1;
        if (kl == k)
            rt[i + 1] = l;

        //cout << "l " << l << endl;
    }

    /*for (i = 1; i <= s.length(); i++)
        cout << lt[i] << ' ' << rt[i] << endl;*/

    for (i = 1; i <= s.length(); i++) {
        if (lt[i] == -1) {
            printf("-1 ");
            continue;
        }

        if (lt[i] == 0)
        {
            printf("1 ");
            update(1, n, 1, i, 1);
            continue;
        }

        //cout << i << ' ' << lt[i] << ' ' << rt[i] <<  "Fd" << endl;
        kl = get(1, n, 1, lt[i], rt[i]);
        //cout << kl << endl;
        //cout << kl << ' ' << lt[i] << ' ' << rt[i] <<  "F" << endl;
        if (kl == INF)
            kl = -2;
        kl++;

        printf("%d ", kl);
        if(kl != -1)
            update(1, n, 1, i, kl);
    }

    return 0;
}

void update(int l, int r, int v, int ind, int x) {
    if (l == r)
    {
        t[v] = min(x, t[v]);
        return;
    }

    int m = (l + r) >> 1;
    if (ind <= m)
        update(l, m, v + v, ind, x);
    else
        update(m + 1, r, v + v + 1, ind, x);
    t[v] = min(t[v + v], t[v + v + 1]);

}

int get(int l, int r, int v, int l1, int r1) {
    if (l1 > r1)
        return INF;
    if ((l == l1) && (r == r1))
        return t[v];

    int m = (l + r) >> 1;
    return min(get(l, m, v + v, l1, min(r1, m)), get(m + 1, r, v + v + 1, max(m + 1, l1), r1));
}
