#include "bits/stdc++.h"
#include <boost/multiprecision/cpp_int.hpp>

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define int128 		boost::multiprecision::uint128_t
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int128,int128>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define N 			15
using namespace std;

pii reduce(pii x){
	int128 gcd=__gcd(x.F,x.S);
	return mp(x.F/gcd,x.S/gcd);
}
pii mult(pii a,pii b){
	return reduce(mp(a.F*b.F,a.S*b.S));
}
pii add(pii a,pii b){
	return reduce(mp(b.S*a.F+b.F*a.S,a.S*b.S));
}
void solve(){
	pii ans=mp(0,1);
	for(int i=0;i<(1<<N);i++){
		int cnt=__builtin_popcount(i);
		if(cnt>N-cnt){
			// wins
			pii prob=mp(1,1);
			rep(j,0,N){
				if(i&(1<<j)){
					// win j-th
					prob=mult(prob,mp(1,j+2));
				}
				else{
					// lose j-th
					prob=mult(prob,mp(j+1,j+2));
				}
			}
			ans=add(ans,prob);
		}
	}
	cout<<floor(boost::numeric_cast<long double>(ans.S)/boost::numeric_cast<long double>(ans.F));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}