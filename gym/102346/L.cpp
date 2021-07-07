#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX

typedef long long ll;



 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);



	ll n;
	cin >> n;

	ll b = __builtin_popcountll(n);

	ll p = 1;
	while(b--){
		p *= 2;
	}

	cout << p << endl;
	// cout << sum << endl;




	return 0;
}