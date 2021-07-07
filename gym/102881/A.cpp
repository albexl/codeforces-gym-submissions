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

    freopen("collectingofficer.in", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        int ans = n + 5;
        for(int i = 0; i < n; i++){
            int match = 0;
            for(int j = i; j < n; j++){
                int pos = s[j] - 'A';
                if(pos == match)
                    match++;
                if(match == 26){
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}