#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(x) (int)((x).size())
#define MAX 30
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<double,double> pii;

signed main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    int tc; cin >> tc;

    while(tc--){

    	ll n; cin >> n;

    	ll b = __builtin_popcountll(n);

    	cout << n + 1 - (1LL << b) << endl;
    }
}