#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)        cerr<<#a<<" : "<<a<<endl
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
#define COLORS      7
#define EACH        10
#define PICK        20
using namespace std;

int facts[max(EACH,COLORS)+1];
int C(int n,int r){
    return facts[n]/(facts[r]*facts[n-r]);
}
vi mult(vi a,vi b){
    vi ans;
    ans.resize(sz(a)+sz(b));
    rep(i,0,sz(a)){
        rep(j,0,sz(b)){
            ans[i+j]+=a[i]*b[j];
        }
    }
    return ans;
}
void solve(){
    facts[0]=1;
    rep(i,1,max(EACH,COLORS)+1)facts[i]=i*facts[i-1];
    vi x;
    x.resize(EACH+1);
    x[0]=0;
    rep(i,1,EACH+1)x[i]=C(EACH,i);
    vi temp={1};
    int ans=0;
    rep(i,1,COLORS+1){
        temp=mult(x,temp);
        ans+=C(COLORS,i)*i*(sz(temp)>PICK?temp[PICK]:0);
    }
    rep(i,0,EACH+1)x[i]=C(EACH,i);
    temp={1};
    rep(i,1,COLORS+1){
        temp=mult(temp,x);
    }
    cout<<ans<<"/"<<(sz(temp)>PICK?temp[PICK]:0);
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