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

    freopen("equal.in", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--){
        set<int> s;
        for(int i = 0, x; i < 3; i++){
            cin >> x;
            s.insert(x);
        }

        cout << (s.size() == 3 ? "NO" : "YES") << endl;
    }

    return 0;
}