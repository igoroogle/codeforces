#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const int DL = 300003;
const int INF = 1E9 + 2;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int del[DL], pr[DL];
vector<int> a[DL];
vector<int> ar = {2, 3, 5, 7, 11, 13};
int main() {
    ios_base::sync_with_stdio(0);
    cout << ar.size() << endl;
    int val = 1;
    for (size_t i = 0; i < ar.size(); ++i) {
        val *= ar[i];
    }

    for (size_t i = 0; i < ar.size(); ++i) {
        cout << val / ar[i] << ' ';
    }
}
