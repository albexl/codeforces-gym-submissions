#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		vector<int> usa(3), ru(3);
		
		for(int i = 0; i < 3; i++)
			cin >> usa[i];
			
		for(int i = 0; i < 3; i++)
			cin >> ru[i];
		
		bool s1 = (usa[0] + usa[1] + usa[2] > ru[0] + ru[1] + ru[2]);
		bool s2 = false;
		
		if(usa[0] > ru[0])
			s2 = true;
		else if(usa[0] == ru[0] && usa[1] > ru[1])
			s2 = true;
		else if(usa[0] == ru[0] && usa[1] == ru[1] && usa[2] > ru[2])
			s2 = true;
		
		cout << usa[0] << " " << usa[1] << " " << usa[2] << " " << ru[0] << " " << ru[1] << " " << ru[2] << endl;
		
		if(s1 && s2)
			cout << "both" << endl;
		else if(s1)
			cout << "count" << endl;
		else if(s2)
			cout << "color" << endl;
		else
			cout << "none" << endl;
		cout << endl;
	}


     //   cout << flush,system("pause");
	return 0;
}