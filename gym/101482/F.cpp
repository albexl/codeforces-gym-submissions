#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> tri;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template<typename T>
static T randint(T lo, T hi) { return uniform_int_distribution<T>(lo, hi)(rng); }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    int k = (n * p + 99) / 100;

    vector<pii> v(n);
    map<int, int> mpx, mpy;

    for(int i = 0; i < n; i++){
    	cin >> v[i].first >> v[i].second;
    	mpx[v[i].first]++;
    	mpy[v[i].second]++;
    }

    for(auto &v : mpx)
    	if(v.second >= k){
    		cout << "possible" << endl;
    		return 0;
    	}

    for(auto &v : mpy)
    	if(v.second >= k){
    		cout << "possible" << endl;
    		return 0;
    	}

    int it = 300;

    while(it--){

    	int l = randint(0, n - 1);
    	int r = randint(0, n - 1);

    	if(l == r)
    		continue;

    	if(v[l].first == v[r].first || v[l].second == v[r].second)
    		continue;

    	int cnt = 0;
    	ll a = v[l].second - v[r].second;
    	ll b = v[l].first - v[r].first;

    	ll g = __gcd(a, b);
    	a /= g;
    	b /= g;

    	ll d = b;
    	ll c = b * v[l].second - a * v[l].first;

    	g = __gcd(c, d);
    	c /= g;
    	d /= g;


    	for(int i = 0; i < n; i++)
    		if(v[i].second * d * b == a * d * v[i].first + b * c)
    			cnt++;
    	

    	if(cnt >= k){
    		cout << "possible" << endl;
    		return 0;
    	}

    }

    cout << "impossible" << endl;

    return 0;
}