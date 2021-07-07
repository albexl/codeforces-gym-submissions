#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
// typedef tree<int, null_mapped_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
static T randint(T lo, T hi)
{
    return uniform_int_distribution<T>(lo, hi)(rng);
}

ll cost(ll x){
    if(x >= 500)
        return x - 100;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = cost(a) + cost(b) + cost(c);
    ans = min(ans, cost(a + b) + cost(c));
    ans = min(ans, cost(a + c) + cost(b));
    ans = min(ans, cost(b + c) + cost(a));
    ans = min(ans, cost(a + b + c));

    cout << ans << endl;

    return 0;
}