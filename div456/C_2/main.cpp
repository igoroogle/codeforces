#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;
typedef  long long ll;
const ll INF = 2E18;
ll boun, inc, dam;
pair<ll, pair<ll, ll>> her[100010], upd[100010];
vector<pair<ll, ll>> ud[100010];
vector<pair<pair<ll, ll>, ll>> ans;
ll ans_val = 0;
void add(ll l, ll r, ll st, ll reg, ll mxh) {
    if (dam > mxh)
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    cin >> boun >> inc >> dam;

    for (ll i = 0; i < n; ++i) {
        cin >> her[i].x >> her[i].y.x >> her[i].y.y;
        ud[i].pb(mp(ll(0), her[i].y.x));
    }

    for (ll i = 0; i < m; ++i) {
        cin >> upd[i].x >> upd[i].y.x >> upd[i].y.y;
    }

    sort(upd, upd + m);
    for (ll i = 0; i < m; ++i) {
        ud[upd[i].y.x - 1].pb(mp(upd[i].x, upd[i].y.y));
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < ll(ud[i].size()) - ll(1); ++j) {
            add(ud[i].x, ud[i + 1].x - 1, ud[i].y, her[i].y.y, her[i].x);
        }
        add(ud[i].back().x, INF, ud[i].back().y, her[i].y.y, her[i].x);
    }


    return 0;
}