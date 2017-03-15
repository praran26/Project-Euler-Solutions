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

void solve(){
    vector<pair<int,pii>>edges;
    rep(_,1,N+1){
        string s;
        cin>>s;
        int curnode=1;
        int curnum=0;
        for(auto i:s){
            if(i==','){
                if(curnum)edges.pb(mp(curnum,mp(_,curnode)));
                curnode++;
                curnum=0;
            }
            else if(i=='-'){
                continue;
            }
            else{
                curnum*=10;
                curnum+=i-'0';
            }
        }
        if(curnum)edges.pb(mp(curnum,mp(_,curnode)));        
    }
    sort(all(edges));
    vi dsu(N+1,-1);
    int ans=0;
    for(auto i:edges){

        int a=i.S.F;
        int b=i.S.S;
        if(a>b)continue;
        while(dsu[a]>0)a=dsu[a];
        while(dsu[b]>0)b=dsu[b];
        if(a==b){
            ans+=i.F;
            continue;
        }
        dsu[b]+=dsu[a];
        dsu[a]=b;
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