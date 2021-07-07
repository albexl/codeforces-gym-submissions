#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(s) ((int)((s).size()))
#define endl '\n'
#define MAX 1000005
#define DEBUG(x) cerr << #x << " = " << x << "\n";

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const ll oo = 0x3f3f3f3f;


int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

   int n; cin >> n;

   vector<int> v(n);

   for(auto &it : v)
	   cin >> it;

   int solve = 0;

   REP(i, 0, n){
	   REP(j, 0, i){
		   if(v[i] < v[j])
			   ++solve;
	   }
   }

   cout << solve << endl;
}