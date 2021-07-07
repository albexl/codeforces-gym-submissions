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

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> rows(n), cols(m);
        for(int i = 0; i < n; i++)
            cin >> rows[i];
        for(int i = 0; i < m; i++)
            cin >> cols[i];

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        // cerr << "here" << endl;

        int ans = 0;

        for(int i = 0; i < (1 << 4); i++){
            vector<int> R, C;
            for(int j = 0; j < 4; j++){
                if(i & (1 << j)){
                    int x = j + 1;
                    R.push_back((x - 1) / 2);
                    C.push_back((x - 1) % 2);
                }
            }

            sort(R.begin(), R.end());
            sort(C.begin(), C.end());

            R.resize(unique(R.begin(), R.end()) - R.begin());
            C.resize(unique(C.begin(), C.end()) - C.begin());

            if(rows == R && cols == C)
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}