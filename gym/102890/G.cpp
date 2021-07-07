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

struct segment_tree
{

    vector<ll> st;

    segment_tree(int n) : st(4 * n)
    {
    }

    void update(int node, int b, int e, int p, ll x)
    {
        if (b == e)
            st[node] = max(st[node], x);
        else
        {
            int m = (b + e) >> 1;
            int l = node << 1;
            int r = l | 1;

            if (p <= m)
                update(l, b, m, p, x);
            else
                update(r, m + 1, e, p, x);

            st[node] = max(st[l], st[r]);
        }
    }

    ll query(int node, int b, int e, int i, int j)
    {
        if (b >= i && e <= j)
            return st[node];

        if (b > j || e < i)
            return 0;

        int m = (b + e) >> 1;
        int l = node << 1;
        int r = l | 1;

        ll L = query(l, b, m, i, j);
        ll R = query(r, m + 1, e, i, j);

        return max(L, R);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    cin >> n;

    vector<ll> g(n + 1), a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i] >> a[i] >> b[i];

    segment_tree st(3 * n);
    ll ans = 0;
    for (int i = n; i >= 1; i--)
    {
        int lo = i + a[i], hi = i + b[i];
        ll mx = st.query(1, 1, 3 * n, lo, hi);
        ll profit = g[i] + mx;
        ans = max(ans, profit);
        st.update(1, 1, 3 * n, i, profit);
    }

    cout << ans << endl;

    return 0;
}