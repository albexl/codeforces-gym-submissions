#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(short I = A;I < B;++I)
#define WAIT cout << flush,system("PAUSE");
#define sz(s) ((int)((s).size()))
#define endl '\n'
#define MAX 1000005

typedef long long ll;
typedef pair<short, short> pii;
typedef vector<int> vi;

const ll MOD = 998244353;

vector<int> cool;

bool cri[MAX];

void C(){

	cri[0] = cri[1] = 1;

	for(int i = 2;i < MAX;++i){
		if(cri[i]) continue;
		cool.push_back(i);
		for(int j = 2*i;j < MAX; j += i)
			cri[j] = 1;
	}

	//cerr << cool.size() << endl;
}

int Solve(int n){

	int ans = 0;

	while(n >= 4){

		++ans;

		for(auto it : cool){

			if(!cri[n - it]){
				//cerr << n << " " << it << " + " << n - it << endl;
				int diff = n - it - it;
				if(diff % 2 == 1) continue;
				n = diff;
				break;
			}
		}
	}

	return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

	C();

//	for(int i = 1000000;i <= 1000000;++i){
//		if(i % 2 == 1) continue;
//		cout << i << " " << Solve(i) << endl;
//	}

	int n; cin >> n;

	cout << Solve(n) << endl;
}