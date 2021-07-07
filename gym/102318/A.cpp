#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ll x, y;
	cin >> x >> y;

	int q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;

		cout << n << " ";

		if(n <= 1000)
			cout << n * x << endl;
		else
			cout << x * 1000 + (n - 1000) * y << endl;

	}
	
	

	return 0;
}