#include <bits/stdc++.h>

using namespace std;

#define IO ios_base::sync_with_stdio(0);cin.tie(0);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  IO;
  int n; cin >> n;
  vector <int> a(n);
  map <int, int> m;

  long double sum = 0;
  for (int i = 0; i < n; ++i) {
  cin >> a[i];
  sum -= m[a[i] - 1];
  sum += m[a[i] + 1];
  m[a[i]]++;
  }

  long double add = 0, minus = n - 1;
  for (int i = 0; i < n; ++i) {
  sum += add * a[i] - minus * a[i];
  ++add;
  --minus;
  }
  printf("%.0Lf\n", sum);

  return 0;
}
