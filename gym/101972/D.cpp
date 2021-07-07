#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(x) ((x).size())
#define MAX 205
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;

    while(tc--){

    	ll n, x, y;

    	cin >> n >> x >> y;

    	ll black = (ll)(ceil(n * 1.0 / 2.0 ));

    	ll white = n - black;

    	if(x >= black && y >= white)
    		cout << "YES\n";
    	else cout << "NO\n";
    }
}