#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

bool vowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

string s;
int n;
const int maxn = 200;
ll dp[maxn][3];

ll solve(int pos, bool vow){
	if(pos == n)
		return 1;
	if(dp[pos][vow] != -1)
		return dp[pos][vow];
	
	ll ans = 0;
	if(s[pos] == '?'){
		if(vow)
			ans += solve(pos + 1, false) * 20;
		else
			ans += solve(pos + 1, true) * 6;
	}
	else if(vowel(s[pos])){
		if(!vow)
			ans += solve(pos + 1, true);
	}
	else{
		if(vow)
			ans += solve(pos + 1, false);
	}
	
	return dp[pos][vow] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		memset(dp, -1, sizeof(dp));
		
		cin >> s;
		n = (int)s.size();
		
		ll ans = 0;
		
		if(s[0] == '?'){
			ans += solve(1, true) * 6;
			ans += solve(1, false) * 20;
		}
		else if(vowel(s[0]))
			ans += solve(1, true);
		else
			ans += solve(1, false);
		cout << "String #" << cases << ": " << ans << endl << endl;
	}

    //    cout << flush,system("pause");
	return 0;
}