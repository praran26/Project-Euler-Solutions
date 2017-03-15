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
#define tr(a)        cerr<<#a<<": "<<a<<endl;
#else
#define tr(a)    
#endif
#define int         long long
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
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define N           40
using namespace std;
int dp[N+1][1024][10];
void solve(){
    int ans=0;
    rep(i,1,N+1){
        if(i==1){
            rep(j,1,10){
                dp[i][1<<j][j]=1;
            }
        }
        else{
            rep(j,0,1024){
                rep(k,0,10){
                    if(!(j&(1<<k)))continue;
                    if(k!=0)dp[i][j][k]+=dp[i-1][j][k-1];
                    if(k!=9)dp[i][j][k]+=dp[i-1][j][k+1];
                    if(k!=0)dp[i][j][k]+=dp[i-1][j&(~(1<<k))][k-1];
                    if(k!=9)dp[i][j][k]+=dp[i-1][j&(~(1<<k))][k+1];
                }
            }
        }
        rep(j,0,10)
        ans+=dp[i][1023][j];
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}