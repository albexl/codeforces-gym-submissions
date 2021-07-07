#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const ll mod = 1e9 + 7;
    const int maxn = 1e5 + 5;

    vector<int> freq(maxn);
    int n;
    cin >> n;

    for(int i = 0, x; i < n; i++){
    	cin >> x;
    	freq[x]++;
    }

    vector<ll> pows(maxn);
    pows[0] = 1ll;
    for(int i = 1; i < maxn; i++)
    	pows[i] = (pows[i - 1] * 2ll) % mod;

    ll ans = 0;
    for(int i = 0; i < maxn; i++){
    	ll cnt = pows[freq[i]];
    	cnt = (cnt + mod - 1) % mod;
    	ans = (ans + cnt) % mod;
    }

    cout << ans << endl;

    return 0;
}