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
#define N  			5000
using namespace std;
set<pair<pair<ll,ll>,pair<ll,ll>>>points;
bool doesIntersect(pii a1,pii a2,pii a3,pii a4){
	int temp1=(a3.F-a4.F)*(a2.S-a3.S)-(a3.S-a4.S)*(a2.F-a3.F);
	int temp2=(a3.F-a4.F)*(a1.S-a3.S)-(a3.S-a4.S)*(a1.F-a3.F);
	return (temp1<0 and temp2>0)or(temp1>0 and temp2<0);
}
void intPoint(pii a1,pii a2,pii a3,pii a4){
	ll num=(a1.S-a2.S)*(a4.F-a2.F)-(a1.F-a2.F)*(a4.S-a2.S);
	ll den=(a1.F-a2.F)*(a3.S-a4.S)-(a1.S-a2.S)*(a3.F-a4.F);
	if((num<=0 and den>=0)or(num>=0 and den<=0))return;
	num=abs(num);
	den=abs(den);
	if(num>=den)return;
	ll xnum=num*a3.F+(den-num)*a4.F;
	ll xden=den;
	ll xgcd=__gcd(xnum,xden);
	xnum/=xgcd;
	xden/=xgcd;
	if(xden<0){
		xden*=-1;
		xnum*=-1;
	}
	ll ynum=num*a3.S+(den-num)*a4.S;
	ll yden=den;
	ll ygcd=__gcd(ynum,yden);
	ynum/=ygcd;
	yden/=ygcd;
	if(yden<0){
		yden*=-1;
		ynum*=-1;
	}
	points.insert(mp(mp(xnum,xden),mp(ynum,yden)));
}
void solve(){
	int curs=290797;
	vi t(4*N);
	rep(i,0,4*N){
		curs=(1LL*curs*curs)%50515093;
		t[i]=curs%500;
	}
	rep(i,0,N){
		rep(j,i+1,N){
			if(doesIntersect(mp(t[i*4],t[i*4+1]),mp(t[i*4+2],t[i*4+3]),mp(t[j*4],t[j*4+1]),mp(t[j*4+2],t[j*4+3]))
				and
				doesIntersect(mp(t[j*4],t[j*4+1]),mp(t[j*4+2],t[j*4+3]),mp(t[i*4],t[i*4+1]),mp(t[i*4+2],t[i*4+3]))){
				intPoint(mp(t[i*4],t[i*4+1]),mp(t[i*4+2],t[i*4+3]),mp(t[j*4],t[j*4+1]),mp(t[j*4+2],t[j*4+3]));
			}
		}
	}
	cout<<sz(points);
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