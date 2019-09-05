#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int dp[200010], n;
char a[200010];

int dfs(int ind) {
    if ((ind < 0) || (ind >= n))
        return -1;

    if (dp[ind] != 0) {
        return dp[ind];
    }

    dp[ind] = 1;
    if (a[ind] == '<')
        dp[ind] = dfs(ind - 1);
    else
        dp[ind] = dfs(ind + 1);
    return dp[ind];
}
int main() {
    cin >> n;
    scanf("\n%s", &a);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (dfs(i) == -1)
                ++ans;
    }
    cout << ans << endl;
}
