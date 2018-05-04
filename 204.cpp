#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"

#define int			long long
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define N			1000000000LL
#define K			100LL
using namespace std;

vi primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; // primes <= K
int totcnt=0;
vi s;
ll ans=0;
void dfs(int idx,ll num,bool type){
	if(idx>=totcnt){
		if(!type)s.emplace_back(num);
		else{
			ans+=upper_bound(all(s),N/num)-s.begin();
		}
		return;
	}
	for(;num<=N;num*=primes[idx]){
		dfs(idx+2,num,type);
		if(num>N/primes[idx])break;
	}
}

void solve(){
	rep(i,0,sz(primes)){
		if(K>=primes[i])totcnt++;
	}
	dfs(0,1,0);
	sort(all(s));
	dfs(1,1,1);
	cout<<ans;
}

signed main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}