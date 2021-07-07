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
		
		ll d, x, s;
		cin >> d >> x >> s;
		
		vector<ll> cups(d), lcost(d), scost(d);
		for(ll i = 0; i < d; i++)
			cin >> cups[i] >> lcost[i] >> scost[i];
		
		ll mnl = 1e15, mns = 1e15;
		
		ll ans = 0;
		
		ll lemons = 0, ounces = 0;
		
		for(ll i = 0; i < d; i++){
			ll lneed = cups[i] * x;
			ll sneed = cups[i] * s;
			
			mnl = min(mnl, lcost[i]);
			mns = min(mns, scost[i]);
			
			if(lneed <= lemons)
				lemons -= lneed;
			else{
				lneed -= lemons;
				lemons = 0;
				ans += lneed * mnl;	
			}
			
			if(sneed <= ounces)
				ounces -= sneed;
			else{
				sneed -= ounces;
				ounces = 0;
				ll cnt = 5 * 16;
				ll am = sneed / cnt + (sneed % cnt != 0);
				ans += am * mns;
				
				ll nounces = am * cnt;
				nounces -= sneed;
				ounces += nounces;
			}
		}
		
		cout << ans << endl;
	}

        //cout << flush,system("pause");
	return 0;
}