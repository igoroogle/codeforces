#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "numbers"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const ll INF64 = 7e18;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979310000;
const ll MD = 535355424;
const ll T = 34539;
const int N = 200100;
const int M = 301;


const int LEN = 1000;
ll n, m, c, k, num, num1, j, step[LEN];
vector <ll> ar[LEN];

int get(ll num)
{
    int res = 0;
    while (num > 0)
    {
        res++;
        num /= 10;
    }

    return res;
}

ll get1(ll num, int cnt)
{
    ll num1 = step[get(num) - cnt];
    return num / num1;
}

ll get2(ll num, int cnt)
{
    ll num1 = step[cnt];
    return num % num1;
}

string get3(ll num, ll cnt)
{
    string st = "", st1 = "";

    for (int i = 0; i < cnt - get(num); i++)
        st = st + "0";
    while (num > 0)
    {
        st1 = char(num % 10 + '0') + st1;
        num /= 10;
    }

    st = st + st1;
    return st;
}

bool check1(ll con, ll reg, ll num)
{
    int cnt, j;

    if (get(con) + get(reg) + get(num) != 11)
        return 0;

    for (j = 0; j < ar[con].size(); j++)
        if (ar[con][j] == reg)
            break;

    if (j == ar[con].size())
        return 0;

    cout << "+" << con << "(" << reg << ")";

    cnt = get(num);
    if (cnt == 3)
        cout << num;
    else if (cnt == 4)
        cout << get3(get1(num, 2), 2) << "-" << get3(get2(num, 2), 2);
    else if (cnt == 5)
        cout << get3(get1(num, 3), 3) << "-" << get3(get2(num, 2), 2);
    else if (cnt == 6)
    {
        cout << get3(get1(num, 2), 2) << "-";
        cout << get3((num % 10000) / 100, 2) << "-";
        cout << get3(get2(num, 2), 2);
    }
    else
    {
        cout << get3(get1(num, 3), 3) << "-";
        cout << get3((num % 10000) / 100, 2) << "-";
        cout << get3(get2(num, 2), 2);
    }

    cout << endl;
    return 1;
}

bool check(ll con, ll num)
{
    if (get(con) + get(num) != 11)
        return 0;

    for (int j = 3; j <= 5; j++)
        if (ar[con].size() > 0 && check1(con, get1(num, j), get2(num, get(num) - j)))
            return 1;

    return 0;
}

int main()
{
    //Freopen;
    FREOPEN;

    step[0] = 1;
    for (int i = 1; i <= 11; i++)
        step[i] = step[i - 1] * 10;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> num;
            ar[c].pb(num);
        }

        sort (ar[c].begin(), ar[c].end());
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        if (get(num) != 11)
        {
            cout << "Incorrect" << endl;
            continue;
        }

        for (j = 1; j <= 3; j++)
            if (check(get1(num, j), get2(num, 11 - j)))
                break;

        if (j == 4)
            cout << "Incorrect" << endl;
    }

    return 0;
}



/*
2
7 3
981
3517
812
351 3
34712
1234
963
8
79818266456
35196328463
78122472557
01234567890
73517960326
35134712239
35112342013
78120203040
*/

