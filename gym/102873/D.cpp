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

    ll a, b;
    cin >> a >> b;

    ll r = b - a;

    if(r <= 0){
        cout << "NO" << endl;
        return 0;
    }

    vector<int> fa(10), fb(10);
    while(a){
        fa[a % 10]++;
        a /= 10;
    }
    while(r){
        fb[r % 10]++;
        r /= 10;
    }

    if(fa == fb)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}