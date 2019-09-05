#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int vl[11];
int main() {
    ios_base::sync_with_stdio(0);
    string a, b, c, d, ans;
    cin >> a >> b;
    if (a.length() < b.length()) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        cout << a << '\n';
        return 0;
    }
    for (size_t i = 0; i < a.length(); ++i) {
        ++vl[a[i] - '0'];
    }
    //cout << "hr " << vl[0] << endl;
    c.resize(a.length());
    bool f;
    for (size_t i = 0; i < b.length(); ++i) {
        //cout << i << endl;
        f = true;
        for (int j = int(b[i] - '0') - 1; j >= 0; --j) {
            if (vl[j] > 0) {
                --vl[j];
                c[i] = char(j + '0');
                //cout << j << " suk\n";
                f = false;
                break;
            }
        }
        if (f) {
            if (vl[b[i] - '0'] == 0) {
                break;
            }
            --vl[b[i] - '0'];
            c[i] = b[i];
            if (int(i) == int(b.length()) - 1) {
                ans = c;
            }
            continue;
        }

        for (size_t j = i + 1; j < a.length(); ++j) {
            for (int k = 9; k >= 0; --k) {
                if (vl[k] > 0) {
                    --vl[k];
                    c[j] = char(k + '0');
                    break;
                }
            }
        }

        if ((ans == "") || (c > ans)) {
            ans = c;
        }

        //cout << "st " << vl[0] << endl;
        for (size_t j = i; j < a.length(); ++j) {
            //cout << i << ' ' << j << ' ' << c[j] << ' ' << int(c[j] - '0') << endl;
            ++vl[c[j] - '0'];
        }
        //cout << i << endl;
        if (vl[b[i] - '0'] == 0) {
            break;
        }
        --vl[b[i] - '0'];
        c[i] = b[i];
        if (int(i) == int(b.length()) - 1) {
            ans = c;
        }
    }
    cout << ans << '\n';
}
