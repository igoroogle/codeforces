#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isgood(int a, int b) {
    return (a <= b);
}

bool islike(int a, int b) {
    return (isgood(a, b) && (2*a >= b));
}

int main() {
    ios_base::sync_with_stdio(0);
    int i, j, k, v1, v2, v3, vm;
    cin >> v1 >> v2 >> v3 >> vm;
    for (i = 1; i <= 503; ++i) {
        for (j = i + 1; j <= 503; ++j) {
            for (k = j + 1; k <= 503; ++k) {
                if (!isgood(vm, i)) {
                    continue;
                }

                if ((islike(vm, k)) || islike(vm, j) || (!islike(vm, i))) {
                    continue;
                }

                if ((!islike(v3, i)) || (!islike(v2, j)) || (!islike(v1, k))) {
                    continue;
                }

                cout << k << '\n' << j << '\n' << i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
