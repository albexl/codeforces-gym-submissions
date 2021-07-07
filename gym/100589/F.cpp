#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

const int mod = 1e9 + 7;
const int maxn = 1000 + 5;
const int maxm = 2e5 + 5;

int dp[maxn], f[maxm], inv[maxm];

int mul(int a, int b, int M){
	return 1ll * a * b % M;
}

int sub(int a, int b, int M)
{
	if (a < b) a += M;
	return a - b;
}

int pow(int a, int b, int M)
{
	int x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) x = mul(x, a, M);
		a = mul(a, a, M);
	}
	return x;
}

int n_k(int n, int k){
	if(k > n)
		return 0;
	int num = f[n];
	int den = mul(inv[k], inv[n - k], mod);
	return mul(num, den, mod);
}

int paths(int xo, int yo, int xi, int yi){
	int n = abs(xo - xi);
	int m = abs(yo - yi);
	return n_k(n + m, n);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	f[0] = 1LL;
	inv[0] = 1ll;
	for(int i = 1; i < maxm; i++){
		f[i] = mul(f[i - 1], i, mod);
		inv[i] = pow(f[i], mod - 2, mod);
	}
	
	int t;
	cin >> t;
	
	while(t--){
		vector<pii> a;
	
		int h, w, n;
		cin >> h >> w >> n;
		
		for(int i = 0, x, y; i < n; i++){
			cin >> x >> y;
			a.push_back({x, y});
		}
		//
		a.push_back({h, w});
		sort(a.begin(), a.end());
		//
		n = (int)a.size();
		///
		for(int i = 0; i < n; i++){
			dp[i] = paths(1, 1, a[i].first, a[i].second);
			for(int j = 0; j < i; j++){
				if(a[j].first <= a[i].first && a[j].second <= a[i].second){
					int cant = mul(dp[j], paths(a[j].first, a[j].second, a[i].first, a[i].second), mod);
					dp[i] = sub(dp[i], cant, mod);
				}
			}
		}
		
		cout << dp[n - 1] << endl;
	}

	return 0;
}