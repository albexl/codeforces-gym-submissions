#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;


bool cool(char a, char b){
	int dif = abs(a - b);
	//cout << a << " " << b << " " << dif << endl;
	return dif == 0 || dif == 1 || dif == 9 || dif == 8 || dif == 10;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	int t;
	cin >> t;
	
	while(t--){
		
		string a, b;
		cin >> a >> b;
		if(a == b){
			cout << 1 << endl;
			continue;
		}
		
		if(a.size() == b.size()){
			bool ok = true;
			for(int i = 0; i < a.size(); i++)
				ok &= cool(a[i], b[i]);
			
			cout << (ok ? "2" : "3") << endl;
		}
		else{
			cout << 3 << endl;
		}
		
	}


	return 0;
}