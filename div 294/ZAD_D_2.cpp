#include <iostream>
#include <map>
typedef long long ll;
using namespace std;
map <ll,ll> klt[27];
ll val[27],sm[100010],ss = 0,i,n;
string s;
int main ()
    {
        for (i=0;i<26;i++) cin >> val[i];
        cin >> s;
        n = s.length();
        sm[0] = 0;
        for (i=1;i<=n;i++) sm[i] = sm[i-1] + val[ll(s[i-1] - 'a')];
        for (i=n;i>=1;i--)
            {
                ss+=klt[ll(s[i-1] - 'a')][sm[n]-sm[i]];
                klt[ll(s[i-1] - 'a')][sm[n]-sm[i-1]]++;
            }
        cout << ss << endl;
        return 0;
    }
