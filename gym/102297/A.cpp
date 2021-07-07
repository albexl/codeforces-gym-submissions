#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;
	
	while(n--){
		
		vector<int> v(10);
		bool s1 = false, s2 = false;
		for(int i = 0; i < 10; i++){
			cin >> v[i];
			if(v[i] == 17)
				s1 = true;
			if(v[i] == 18)
				s2 = true;
		}
		for(int i = 0; i < 10; i++)
			cout << v[i] << " \n"[i == 9];
		if(s1 && s2)
			cout << "both" << endl;
		else if(s1)
			cout << "zack" << endl;
		else if(s2)
			cout << "mack" << endl;
		else
			cout << "none" << endl;
		cout << endl;
		
	}

      //  cout << flush,system("pause");
	return 0;
}