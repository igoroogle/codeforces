#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    stack<char> st;
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((st.empty()) || (st.top() != s[i])) {
            st.push(s[i]);
        } else {
            st.pop();
            ++ans;
        }
    }

    if (ans % 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
