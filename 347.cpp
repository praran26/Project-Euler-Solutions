#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<": "<<a<<endl;
#else
#define tr(a)    
#endif
#define int 		long long
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
#define N 			10000000
using namespace std;
vi sieve[N+1];
set<int>primecouples[N+1];
void solve(){
	vi primes;
	rep(i,2,N+1){
		if(sieve[i].empty()){
			for(int j=i;j<=N;j+=i){
				if(sz(sieve[j])<3)sieve[j].pb(i);
			}
			primes.pb(i);
		}
	}
	int ans=0;
	for(int i=N;i>=2;i--){
		if(sz(sieve[i])!=2)continue;
		if(primecouples[sieve[i][0]].count(sieve[i][1]))continue;
		ans+=i;
		primecouples[sieve[i][0]].insert(sieve[i][1]);
	}
	cout<<ans;
}

signed main(){
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