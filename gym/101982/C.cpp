#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(short I = A;I < B;++I)
#define WAIT cout << flush,system("PAUSE");
#define sz(s) ((int)((s).size()))
#define endl '\n'
#define MAX 1005

typedef long long ll;
typedef pair<short, short> pii;
typedef vector<int> vi;

const ll MOD = 998244353;

vector<int> v, cool;

ll dp[4*MAX][MAX];

set<int> ss;

void Compress(){

	map<int, int> mmap;

	vector<int> aux;

	for(auto it : v)
		aux.push_back(it);

	sort(aux.begin(), aux.end());

	int cont = 1;

	for(auto it : aux){
		if(mmap.find(it) == mmap.end()){
			mmap[it] = cont++;
		}
	}

	cool.resize(sz(v));

	REP(i, 0, sz(v))
		cool[i] = mmap[v[i]];
}

void Update(int k, int n, int b, int e, int i, ll val){

	if(b == e && b == i)
		dp[n][k] = (dp[n][k] + val) % MOD;
	else{

		int m = (b + e) >> 1;

		if(i <= m)
			Update(k, 2*n, b, m, i, val);
		else Update(k, 2*n + 1, m + 1, e, i, val);
		dp[n][k] = (dp[2 * n][k] + dp[2 * n + 1][k]) % MOD;
	}
}

ll Query(int k, int n, int b, int e, int i, int j){

	if(b > j || e < i)
		return 0;

	if(b >= i && e <= j)
		return dp[n][k];

	int m = (b + e) >> 1;

	ll l = Query(k, 2*n, b, m, i, j);
	ll r = Query(k, 2*n + 1, m + 1, e, i, j);

	return (l + r) % MOD;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    v.resize(n);
    for(auto &it : v)
    	cin >> it;

    Compress();

    //for(auto it : cool) cerr << it << " \n";

    for(auto it : cool){
    	Update(1, 1, 1, n, it, 1);
    	ss.insert(it);
    }
    for(int i = 2; i <= k;++i){

    	for(auto it : cool){

    		ll aux = Query(i - 1, 1, 1, n, 1, it - 1);

    		Update(i, 1, 1, n, it, aux);
    	}
    }

    ll solve = 0;

    for(auto it : ss){
    	solve = (solve + Query(k, 1, 1, n, it, it)) % MOD;
    }

    cout << solve << endl;
}