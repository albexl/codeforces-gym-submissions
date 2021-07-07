#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;


bool ok(string &s){
	int lo = 0, hi = s.size() - 1;
	while(lo <= hi){
		if(s[lo++] != s[hi--])
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("points.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	int ans = 0;

	while(t--){
		string s;
		cin >> s;
		ans += ok(s);
	}

	cout << ans << endl;

	
	return 0;	
}