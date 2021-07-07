#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, int> pii;

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("buffcraft.in", "r", stdin);
    freopen("buffcraft.out", "w", stdout);

    ll b;
    int k, n, m;
    cin >> b >> k >> n >> m;

    vector<pii> v, w;

    for(ll i = 0; i < n; i++){
    	ll x;
    	cin >> x;
    	if(x > 0)
    		v.push_back({x, i});
    }

    for(int i = 0; i < m; i++){
    	ll x;
    	cin >> x;
    	if(x > 0)
    		w.push_back({x, i});
    }

    sort(v.rbegin(), v.rend());
    sort(w.rbegin(), w.rend());

    n = v.size();
    m = w.size();

    vector<ll> sum(m);

    if(m){
    	sum[0] = w[0].first;
    	for(int i = 1; i < m; i++)
    		sum[i] = sum[i - 1] + w[i].first;
    }

    ll ans = b;
    int p1 = 0, p2 = 0;

    ll s = b;

    for(int i = 0; i <= min(k, n); i++){

    	int need = min(k - i, m);

    	ll cur = s;

    	int idx1 = i;
    	int idx2 = 0;

		ll cur2 = 100;

    	if(need > 0){
    		idx2 = need;
    		cur2 += sum[need - 1];
    	}

    	if(cur * cur2 > ans){
    		ans = cur * cur2;
    		p1 = idx1;
    		p2 = idx2;
    	}

    	if(i < n)
    		s += v[i].first;
    }

    cout << p1 << " " << p2 << endl;
    for(int i = 0; i < p1; i++)
    	cout << v[i].second + 1 << " \n"[i + 1 == p1];
    for(int i = 0; i < p2; i++)
    	cout << w[i].second + 1 << " \n"[i + 1 == p2];


    return 0;
}