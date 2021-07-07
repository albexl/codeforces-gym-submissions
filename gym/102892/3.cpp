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
    string s;
    cin >> n >> s;

    int ans = 0;
    vector<bool> f(n);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            int p = i;
            while(p >= 0 && !f[p] && s[p] != 'b'){
                ans++;
                f[p] = true;
                p--;
            }

            p = i + 1;
            while(p < n && !f[p] && s[p] != 'b'){
                ans++;
                f[p] = true;
                p++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}