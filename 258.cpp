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
using namespace std;
int solver(vi initials,vi coeff,ll n){
	if(n<sz(initials))return initials[n];
	vi newcoeff(2*sz(coeff)-1);
	rep(i,0,sz(coeff)){
		rep(j,0,sz(coeff)){
			newcoeff[i+j]=(newcoeff[i+j]+1LL*coeff[i]*(j%2?-1:1)*coeff[j])%20092010;
		}
	}
	rep(i,0,sz(coeff)-1){
		int sum=0;
		for(int j=sz(coeff)-1;j>0;j--){
			sum=(sum-1LL*initials[i+sz(coeff)-j-1]*coeff[j])%20092010;
		}
		initials.pb(sum);
	}
	for(int i=0;i<sz(coeff);i++){
		newcoeff[i]=newcoeff[2*i];
	}
	newcoeff.resize(sz(coeff));
	vi newinits(sz(newcoeff)-1);
	for(int i=n%2;i<sz(initials);i+=2)newinits[i/2]=initials[i];
	return solver(newinits,newcoeff,n/2);
}
void solve(){
	vi coeff;
	coeff.pb(1);
	rep(i,1,1999)coeff.pb(0);
	coeff.pb(-1);
	coeff.pb(-1);
	vi init(2000,1);
	cout<<(solver(init,coeff,1000000000000000000)+20092010)%20092010;
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