#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX
 
typedef long long ll;
typedef pair<int, int> pii;

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
	ll v, n;
	cin >> v >> n;

	ll t = v * n;

	for(ll i = 10; i <= 90; i += 10)
		cout << (i * t) / 100 + ( ((i * t) % 100) != 0) << " \n"[i == 90];


	return 0;
}