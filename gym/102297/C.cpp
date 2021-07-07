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
		
		ll n, b;
		cin >> n >> b;
		
		cout << "Practice #" << cases << ": " << n << " " << b << endl;
		
		int q;
		cin >> q;
		
		while(q--){
			
			ll x;
			cin >> x;
			
			while(b <= x)
				b *= 2;
			
			b -= x;
			
			cout << x << " " << b << endl;
			
		}
		
		cout << endl;
	}

    //    cout << flush,system("pause");
	return 0;
}