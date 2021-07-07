#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll m;
    cin >> n >> m;

    vector<pii> a, b;

    for(int i = 1; i <= n; i++){
    	ll x, y;
    	cin >> x >> y;
    	if(y == 1)
    		a.push_back({x, i});
    	else
    		b.push_back({x, i});
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    vector<ll> sum(b.size());

    for(int i = 0; i < b.size(); i++){
    	sum[i] = b[i].first;
    	if(i)
    		sum[i] += sum[i - 1];
    }

    int ans = 1e9;
    int low = 0;

    ll s = 0;

    int p1 = -1, p2 = -1;

    for(int i = 0; i <= a.size(); i++){

    	int lo = 0, hi = b.size() - 1, pos = -1;

    	// cout << i << " " << s << " :" << endl;

    	while(lo <= hi){
    		int mid = (lo + hi) >> 1;
    		if(sum[mid] >= m - s){
    			pos = mid;
    			hi = mid - 1;
    		}
    		else lo = mid + 1;
    	}

    	// cout << pos << endl;

    	ll X = s;
    	
    	if (pos != -1 && X >= m)
    	    pos = -1;

    	if(pos != -1)
    		X += sum[pos];

    	if(X < m){
    		if(i != a.size())
    			s += a[i].first;
    		continue;
    	}

    	int cnt = i + pos + 1;
    	if(cnt < ans){
    		ans = cnt;
    		low = i;
    		p1 = i - 1;
    		p2 = pos;    		
    	}
    	else if(cnt == ans && i > low){
    		low = i;
    		p1 = i - 1;
    		p2 = pos;
    	}

    	if(i != a.size())
    		s += a[i].first;
    }

    cout << ans << " " << low << endl;
    // cout << p1 << " " << p2 << endl;
    vector<ll> idx;
    for(int i = 0; i <= p1; i++)
    	idx.push_back(a[i].second);
    for(int i = 0; i <= p2; i++)
    	idx.push_back(b[i].second);

    for(int i = 0; i < idx.size(); i++)
    	cout << idx[i] << " \n"[i + 1 == idx.size()];



    return 0;
}