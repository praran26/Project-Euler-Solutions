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
#define N 			9
using namespace std;

void solve(){
	int x[4][4];
	rep(i,0,4){
		rep(j,0,4){
			x[i][j]=10;
		}
	}
	ll ans=0;
	rep(a,0,N+1){
		x[0][2]=a;
		rep(b,0,N+1){
			x[1][0]=b;
			rep(c,0,N+1){
				x[1][1]=c;
				rep(d,0,N+1){
					x[1][3]=d;
					rep(e,0,N+1){
						x[2][0]=e;
						rep(f,0,N+1){
							x[2][1]=f;
							rep(g,0,N+1){
								x[2][3]=g;
								rep(h,0,N+1){
									x[3][0]=h;
									int tempsum=x[1][1]*2+x[2][1]*2-x[0][2]*2;
									if(tempsum%2)continue;
									x[3][2]=tempsum/2;
									bool isGood=1;
									x[3][3]=x[3][0]-x[1][1]+x[2][0]+x[0][2]+x[3][2]-x[1][1]-x[1][3];
									x[0][3]=x[1][0]-x[2][1]-x[3][0]+x[1][1]+x[1][3];
									x[2][2]=x[1][0]-x[0][2]+x[1][1]+x[1][3]-x[3][2];
									x[0][1]=x[1][0]+x[2][0]+x[3][0]-x[0][2]-x[0][3];
									x[0][0]=x[0][3]+x[1][3]+x[2][3]-x[1][1]-x[2][2];
									x[1][2]=x[1][3]+x[2][3]+x[3][3]-x[2][1]-x[3][0];
									x[3][1]=x[0][3]+x[1][3]+x[2][3]-x[3][0]-x[3][2];
									rep(p,0,4){
										rep(q,0,4){
											if(x[p][q]>N or x[p][q]<0)isGood=0;
										}
									}
									if(isGood){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
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