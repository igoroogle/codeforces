#include "bits/stdc++.h"

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "forest"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 7e18;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979310000;
const ll MD = 535355424;
const ll T = 34539;
const int N = 200101;
const int M = 505;

int n, m, ar[110][110], res, f, ar1[110][110], use[110][110], n1, n2;
pair <int, int> q[400000], q1[400000];

bool check(int i, int j)
{
    if (i > 0 && ar[i - 1][j] - ar[i][j] == 1)
        return 1;
    if (j > 0 && ar[i][j - 1] - ar[i][j] == 1)
        return 1;
    if (i < n - 1 && ar[i + 1][j] - ar[i][j] == 1)
        return 1;
    if (j < m - 1 && ar[i][j + 1] - ar[i][j] == 1)
        return 1;

    return 0;
}

void check1(int i, int j)
{
    if (i > 0 && ar[i - 1][j] - ar[i][j] == -1 && !use[i - 1][j])
    {
        use[i - 1][j] = 1;
        q1[n1] = mp(i - 1, j);
        n1++;
    }
    if (j > 0 && ar[i][j - 1] - ar[i][j] == -1 && !use[i][j - 1])
    {
        use[i][j - 1] = 1;
        q1[n1] = mp(i, j - 1);
        n1++;
    }
    if (i < n - 1 && ar[i + 1][j] - ar[i][j] == -1 && !use[i + 1][j])
    {
        use[i + 1][j] = 1;
        q1[n1] = mp(i + 1, j);
        n1++;
    }
    if (j < m - 1 && ar[i][j + 1] - ar[i][j] == -1 && !use[i][j + 1])
    {
        use[i][j + 1] = 1;
        q1[n1] = mp(i, j + 1);
        n1++;
    }
}

int main()
{
    FREOPEN;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            //cin >> ar[i][j];
            scanf("%i", &ar[i][j]);

            q1[n1] = mp(i, j);
            n1++;
        }

    while (1 == 1)
    {
        f = 1;

        n2 = 0;
        for (int i = 0; i < n1; i++)
            if (check(q1[i].f, q1[i].s))
            {
                q[n2] = q1[i];
                n2++;
            }

        n1 = 0;
        for (int i = 0; i < n2; i++)
            if (!use[q[i].f][q[i].s])
            {
                use[q[i].f][q[i].s] = 1;
                ar[q[i].f][q[i].s]++;
            }

        for (int i = 0; i < n2; i++)
            use[q[i].f][q[i].s] = 0;

        /*
        cout << "-------------------\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << ar[i][j] << " ";
            cout << endl;
        }
        */

        for (int i = 0; i < n2; i++)
        {
            q1[n1] = q[i];
            n1++;
            check1(q[i].f, q[i].s);
        }

        for (int i = 0; i < n1; i++)
            use[q1[i].f][q1[i].s] = 0;

        if (n1 == 0)
            break;
        res++;
    }

    cout << res << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            //cout << ar[i][j] << " ";
            printf("%i ", ar[i][j]);
        cout << endl;
    }
}


/*





*/


