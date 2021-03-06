#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)        cerr<<#a<<" : "<<a<<endl
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
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define MAXN        12345
using namespace std;

void solve(){
    ll ans=0;
    for(int N=3;N<=MAXN;N++){
        for(int i=1;N-(3*i-1)>0;i++){
            ll k=(N-(3*i-1));
            ans+=i*k*(k+1)/2;
        }
    }
    cout<<ans;
}

int main(){
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