#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("mahdi.in", "r", stdin);

    int t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++){

    	cout << "Case " << cases << ":" << endl;

    	char a;
    	int len, mul, sum;

    	cin >> a >> len >> mul >> sum;

    	vector<char> v;
    	v.push_back(a);
    	
    	for(int i = 1; v.size() < min(len, 26 * 26 * 3 + 1); i++){
    		char c = (char)(97 + ( ((int)v.back() - 97) * mul + i * sum) % 26);
    		v.push_back(c);
    	}

    	int q;
    	cin >> q;

    	while(q--){

    		cin >> a >> len >> mul >> sum;

    		vector<char> w;
	    	w.push_back(a);

	    	for(int i = 1; w.size() < len ; i++){
	    		char c = (char)(97 + ( ((int)v.back() - 97) * mul + i * sum) % 26);
	    		w.push_back(c);
	    	}

	    	int pos = 0;
	    	for(int i = 0; i < v.size() && pos < w.size(); i++){
	    		if(w[pos] == v[i])
	    			pos++;
	    	}

	    	cout << ( (pos == w.size()) ? "BRAVO" : "REPEAT") << endl;
    	}
    }

    return 0;
    
}