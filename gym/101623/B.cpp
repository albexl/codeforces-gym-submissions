#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;




int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	if(n <= 3)
		cout << 1 << endl;
	else
		cout << n - 2 << endl;



	return 0;
}