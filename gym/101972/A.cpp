#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(x) (int)((x).size())
#define MAX 205
#define endl '\n'

typedef long long ll;
typedef pair<double,double> pii;


vector<ll> Convert(ll n){

	bool neg = false;

	if(n < 0) neg = true;

	n = abs(n);

	ll pot = 1;

	vector<ll> ans;

	while(n){

		ll r = n % 10;

		if(r)
			ans.push_back(r*pot);

		pot *= 10;

		n /= 10;
	}

	if(neg){
		REP(i, 0, sz(ans))
			ans[i] *= -1;
	}

	return ans;
}


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;

    while(tc--){

    	ll n, m;

    	cin >> n >> m;

    	vector<ll> v = Convert(n), w = Convert(m);

    	for(int i = 0;i < sz(v);++i){
    		for(int j = 0;j < sz(w);++j){
    			if(i == sz(v) - 1 && j == sz(w) - 1)
    				cout << v[i] << " x " << w[j] << "\n";
    			else
    				cout << v[i] << " x " << w[j] << " + ";
    		}
    	}
    }
}