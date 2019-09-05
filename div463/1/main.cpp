#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    cout << s;
    reverse(s.begin(), s.end());
    cout << s << endl;
}
