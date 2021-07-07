#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string dummy;
    getline(cin, dummy);

    vector<string> lines(n);
    for(int i = 0; i < n; i++)
    	getline(cin, lines[i]);


    vector<vector<pair<int, pii>>> g(26);
    int depth = 0;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < lines[i].size(); j++){

    		if(lines[i][j] >= 'a' && lines[i][j] <= 'z'){

    			if(!g[lines[i][j] - 'a'].empty()){

    				auto prv = g[lines[i][j] - 'a'].back();
    				int x = prv.second.first;
    				int y = prv.second.second;
    				cout << i + 1 << ":" << j + 1 << ": " << "warning: shadowed declaration of " << lines[i][j] << ", the shadowed position is " << x + 1 << ":" << y + 1 << endl;
    			}

    			g[lines[i][j] - 'a'].push_back({depth, {i, j}});

    		}

    		if(lines[i][j] == '{'){
    			depth++;
    		}
    		else if(lines[i][j] == '}'){

    			for(int k = 0; k < 26; k++){
    				if(!g[k].empty() && g[k].back().first == depth){
    					g[k].pop_back();
    				}
    			}

    			depth--;
    		}
    	}
    }

    return 0;
}