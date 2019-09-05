#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct bor
{
    bor *t[26];
    int v, p;
    bor()
    {
        v = -1;
        p = -1;
        for (int i = 0; i < 26; i++)
            t[i] = NULL;
    }
};

int getchar(char c)
{
    return int(c - 'a');
}

void add(string& s, int n, int ind, bor *b)
{
    if (ind >= n)
        return;
    int tc = getchar(s[ind]);
    if (b->t[tc] == NULL)
        b->t[tc] = new bor();
    add(s, n, ind + 1, b->t[tc]);
}

int recwin(bor *b)
{
    if (b->v != -1)
        return b->v;

    int i, w = 2;

    for (i = 0; i < 26; i++)
        if ((b->t[i] != NULL) && (recwin(b->t[i]) == 2))
        {
            w = 1;
            break;
        }

    b->v = w;
    return w;
}

int reclose(bor *b)
{
    if (b->p != -1)
        return b->p;

    int i, l = -1;

    for (i = 0; i < 26; i++)
    {
        if ((b->t[i] != NULL) && (reclose(b->t[i]) == 2))
            l = 1;
        else if ((l == -1) && (b->t[i] != NULL) && (reclose(b->t[i]) == 1))
            l = 2;
    }

    if (l == -1)
        l = 1;
    b->p = l;
    return l;
}

string s;
bor *b = new bor();
int main()
{
    int n, k, i;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        add(s, s.length(), 0, b);
    }

    if ((recwin(b) == 1) && (reclose(b) == 1))
        cout << "First\n";
    else if ((reclose(b) == 2) && (recwin(b) == 2))
        cout << "Second\n";
    else if ((recwin(b) == 1) && (k % 2))
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}
