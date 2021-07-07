#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){

    	string s;
    	cin >> s;

    	string ans = "";

    	for(auto &c : s){

    		bool upper = (c >= 'A' && c <= 'Z');

    		for(int j = 0; j < 13; j++){
    			c++;
    			if(upper && c > 'Z')
    				c = 'A';
    			if(!upper && c > 'z')
    				c = 'a';
    		}

    		ans += c;

    	}

    	reverse(ans.begin(), ans.end());
    	for(auto &c : ans){
    		if(c >= 'a' && c <= 'z')
    			c = toupper(c);
    		else
    			c = tolower(c);
    	}
    	cout << ans << endl;

    }
 

    return 0;
}