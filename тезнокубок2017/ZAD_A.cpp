#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int i = 0, j;
    while (i < n) {
        if ((i < n - 2) && (s.substr(i, 3) == "ogo")) {
            j = i + 3;
            cout << "***";
            while ((j < n - 1) && (s.substr(j, 2) == "go")) {
                j += 2;
            }

            i = j;
        } else {
            cout << s[i];
            ++i;
        }
    }
    cout << endl;
}
