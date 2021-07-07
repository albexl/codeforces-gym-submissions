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



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    cin >> n;

    ll k;
    cin >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for(int i = 0; i < n; i++){
        ll mn = a[i], mx = a[i];
        for(int j = i; j < n; j++){
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            if(mx - mn == k)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}