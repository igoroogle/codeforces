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

string s = "      ", s1;
int main()
{
    freopen("reading.in", "r", stdin);
    //freopen("reading.out", "w", stdout);
    while (cin >> s1)
        s += " " + s1;
    s += "      ";
    for (int i = 1; i < s.length() - 1; i++)
        if (!(s[i] == 'a' || s[i] == 'A' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O') && s[i - 1] == ' ' && s[i + 1] == ' ')
        {
            //cout << s[i - 1] << s[i] << s[i + 1] << s[i + 2] << s[i + 3];
            cout << "Dreaming\n";
            return 0;
        }

    cout << "Real life\n";

    return 0;
}
