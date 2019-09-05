#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    ans = a + b + c + d;
    if (ans == 2) {
        cout << 0 << endl;
    } else if (ans == 0) {
        cout << 0 << endl;
    } else if (ans == 1) {
        cout << 1 << endl;
    } else {
        for(;;);
    }
}
