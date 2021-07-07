#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;

bool palin(vector<int> &v){
	int lo = 0, hi = v.size() - 1;
	while(lo <= hi){
		if(v[lo] != v[hi])
			return false;
		lo++;
		hi--;
	}
	return true;
}

vector<int> get(int n, int b){

	vector<int> ans;

	if(n == 0){
		ans.push_back(0);
		return ans;
	}

	while(n){
		ans.push_back(n % b);
		n /= b;
	}

	return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 

    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;

    	vector<pair<int, vector<int>>> v;

    	for(int i = 2; i <= 16; i++)
    		v.push_back({i, get(n, i)});
    	
    	vector<int> ans;
    	for(auto &p : v)
    		if(palin(p.second))
    			ans.push_back(p.first);

    	if(ans.empty())
    		cout << -1 << endl;
    	else{
    		for(int i = 0; i < ans.size(); i++)
    			cout << ans[i] << " \n"[i + 1 == ans.size()];
    	}
    }

    return 0;
}