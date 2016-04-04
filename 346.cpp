#include <bits/stdc++.h>
#define gcd(a,b) __gcd(a,b)
#define ll long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vi>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define all(a) a.begin(),a.end()
#define sum(a) accumulate(all(a),0)
#define endl '\n'
#define hell 1000000007
using namespace std;
set<ll>x;
int main()
{
    x.insert(1);
    rep(i,2,1000000){
        ll cur=i*i+i+1;
        while(true){
            if(cur>1000000000000)break;
            x.insert(cur);
            cur*=i;
            cur++;
        }
    }
    ll ans=0LL;
    for(auto i=x.begin();i!=x.end();i++){
        ans+=*i;
    }
    cout<<ans;
    return 0;
}
