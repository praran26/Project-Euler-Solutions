#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

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
using namespace std;

vi primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int cnt=sz(primes);
vector<int>s;

void dfs(int idx,ll num){
	if(idx==cnt){
		s.emplace_back(num);
		return;
	}
	for(;num<=hell-7;num*=primes[idx]){
		dfs(idx+1,num);
	}
}

void solve(){
	dfs(0,1);
	cout<<sz(s);
}

int main(){
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