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

struct union_find
{
    vector<int> p;

    union_find(int n) : p(n, -1) {}

    bool join(int u, int v)
    {
        if ((u = root(u)) == (v = root(v)))
            return false;
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v];
        p[v] = u;
        return true;
    }

    int root(int u)
    {
        return p[u] < 0 ? u : p[u] = root(p[u]);
    }
};

bool match(string &a, string &b)
{

    if (a.size() != b.size())
        return false;

    int n = b.size();

    for (int i = 0; i < n; i++)
    {
        int pos = 0, idx = i, cnt = 0;
        bool ok = true;
        while (cnt < n)
        {
            if (a[pos] != b[idx]){
                ok = false;
                break;
            }
            pos++;
            idx = (idx + 1) % n;
            cnt++;
        }

        if(ok)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    cin >> n;

    vector<string> a(n);
    union_find ds(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (match(a[i], a[j]))
                ds.join(i, j);

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (ds.root(i) == i)
            ans++;

    cout << ans << endl;

    return 0;
}