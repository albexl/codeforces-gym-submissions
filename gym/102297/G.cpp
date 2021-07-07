#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		cout << "Grid #" << cases << ": ";
		
		ll k, n;
		cin >> k >> n;
		
		ll mx = (n - 1) * (n - 1) + 1;
		if(k > mx)
			cout << "impossible" << endl << endl;
		else
			cout << k * (n - 1) * 2 << endl << endl;
		
	}

      //  cout << flush,system("pause");
	return 0;
}