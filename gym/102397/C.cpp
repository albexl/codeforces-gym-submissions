#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
    	if(s[i] == 'U')
    		y++;
    	if(s[i] == 'D')
    		y--;
    	if(s[i] == 'R')
    		x++;
    	if(s[i] == 'L')
    		x--;
    }

    cout << x << " " << y << endl;

    return 0;
}