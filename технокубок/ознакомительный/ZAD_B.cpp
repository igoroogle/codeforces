#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
string s;
int main()
{
    cin >> s;
    int n = s.length(), i, j, kl = 0;
    for (i = n / 2 + 1; i < n; i++)
        if (s.substr(0, i) == s.substr(n - i, n))
        {
            cout << "YES\n";
            cout << s.substr(0, i) << endl;
            return 0;
        }

    cout << "NO\n";
    return 0;
}
