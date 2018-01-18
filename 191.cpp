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
#define N 			30
using namespace std;

map<string,ll>v[N+1];
void solve(){
	vector<string>p={"OO","AA","OA","AO"};
	for(auto i:p)v[2][i]=1;
	rep(i,3,N+1){
		for(auto j:p){
			for(auto k:p){
				if(k[1]==j[0] and !(j=="AA" and k=="AA")){
					v[i][j]+=v[i-1][k];
				}
			}
		}
	}
	vector<ll>dp(N+1);
	dp[0]=1;
	dp[1]=2;
	rep(i,1,N+1){
		for(auto j:v[i])dp[i]+=j.S;
	}
	int ans=dp[N]; // answers without L
	for(int i=0;i<N;i++){
		ans+=dp[i]*dp[N-1-i]; // answers with L at i-th position
	}
	cout<<ans;
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