#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
// typedef tree<int, null_mapped_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    string s, x;
    cin >> n >> s >> x;

    ll ans = 0;
    int last = -1;

    for(int i = 0; i + 1 < n; i++){
        if(s[i] == x[0] && s[i + 1] == x[1]){

            ans += 1ll * (i - last) * (n - 1 - (i + 1) + 1);
            last = i;
        }
    }

    cout << ans << endl;

    return 0;
}