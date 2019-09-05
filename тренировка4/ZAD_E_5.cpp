#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(a) ((a) * (a))
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const ll MD = 1248742437;
const ll T = 378531;
const int N = 200001;
const int M = 100000;

string s = "        ", s1, s2;
map<string, bool> b;
int kol = 0;
int main()
{
    freopen("reading.in", "r", stdin);
    //freopen("reading.out", "w", stdout);
    b["he"] = 1;
    b["the"] = 1;
    b["an"] = 1;
    b["she"] = 1;
    b["it"] = 1;
    b["they"] = 1;
    b["you"] = 1;
    b["we"] = 1;
    b["are"] = 1;
    b["them"] = 1;
    b["for"] = 1;
    b["in"] = 1;
    b["does"] = 1;
    b["do"] = 1;
    b["yes"] = 1;
    b["no"] = 1;
    b["body"] = 1;
    b["head"] = 1;
    b["over"] = 1;
    while (getline(cin, s1))
        s += " " + s1;
    s += "       ";
    s2 = "";
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (!(((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z'))))
        {
            kol += int(b[s2]);
            s2 = "";
        }
        else
            s2 += s[i];
    }

    cout << kol << endl;

    return 0;
}
