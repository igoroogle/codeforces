#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    map<string, string> val;
    val["purple"] = "Power";
    val["green"] = "Time";
    val["blue"] = "Space";
    val["orange"] = "Soul";
    val["red"] = "Reality";
    val["yellow"] = "Mind";
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        val.erase(s);
    }

    cout << val.size() << '\n';
    for (auto cur: val) {
        cout << cur.second << '\n';
    }
}
