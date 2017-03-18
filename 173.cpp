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
#define N 			1000000
using namespace std;

void solve(){
	vi dp(N+1);
	for(int i=1;i*i<N+1;i++){
		for(int j=i*i+2*i,k=i+2;j<N+1;j+=2*i,k+=2){
			//a+b=k,a-b=i
			int a=(k+i)/2;
			int b=(k-i)/2;
			if((a^b)&1)continue;
			dp[j]++;
		}
	}
	cout<<accumulate(dp.begin(),dp.end(),0LL);
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