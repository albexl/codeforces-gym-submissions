#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

bool cmp(pii a, pii b){
	if(a.second - a.first > 0){
		if(b.second - b.first <= 0)return true;
		return a.first < b.first;
	}
	if(b.second - b.first > 0)return false;
	return a.second > b.second;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;
	vector<pii> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), cmp);
	
	ll ans = 0, cap = 0;
	for(auto &e : a){
		ll A = e.first, B = e.second;
		if(cap < A){
			ans += A - cap;
			cap = A;
		}
		cap -= A;
		cap += B;
	}
	
	cout << ans << endl;
	
	return 0;
}