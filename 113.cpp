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
#define N           100
using namespace std;
int dp1[N+1][10];
int dp2[N+1][10];    
void solve(){
    //dp1[n][k]=number of increasing numbers ending with digit k
    //dp2[n][k]=number of decreasing numbers ending with digit k
    int ans=0;
    rep(i,1,N+1){
        rep(j,0,10){
            if(i==1)dp1[i][j]=dp2[i][j]=bool(j);
            else{
                rep(k,0,10){
                    dp1[i][j]+=dp1[i-1][k]*bool(k<=j);
                    dp2[i][j]+=dp2[i-1][k]*bool(k>=j);
                }
                ans+=dp1[i][j]+dp2[i][j];
            }
        }
    }
    ans-=9*N;
    ans+=18;
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