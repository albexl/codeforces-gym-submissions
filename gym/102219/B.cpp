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


	int t;
	cin >> t;
	while(t--){
		ll x, y;
		cin >> x >> y;
		if(x == y)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	

	return 0;
}