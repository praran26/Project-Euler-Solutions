#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define Max(a,b)    ((a)>(b)?(a):(b))
#define Min(a,b)    ((a)<(b)?(a):(b))
#define rep(i,a,b)  for (__typeof(b) i=a;i!=b;i+=1)
#define all(a)      a.begin(),a.end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
using namespace std;
int digitsum(ll k){
    int ans=0;
    while(k){
        ans+=k%10;
        k/=10;
    }
    return ans;
}
bool isPrime(ll N) {													//determines if the argument is prime or not (deterministic)
	if(N<2)return false;
	if(N<4)return true;
	if((N&1)==0)return false;
	if(N%3==0)return false;
	ll curr=5;
	while (curr<=sqrt(N)){
		if(N%curr==0)return false;
		curr+=2;
		if(N%curr==0)return false;
		curr+=4;
	}
	return true;
}
bool isStrong(ll k){
    return isPrime(k/digitsum(k));
}

void solve(){
    map<ll,bool>m;
    queue<ll>k;
    rep(i,1,10){
        k.push(i);
        m[i]=1;
    }
    while(!k.empty()){
        ll cur=k.front();
        k.pop();
        if(10*cur>=1e14)continue;
        rep(i,0,10){
            if((cur*10+i)%(digitsum(cur*10+i))==0){
                m[cur*10+i]=1;
                k.push(cur*10+i);
            }
        }
    }
    set<ll>alpha;
    for(auto i:m){
        if(isStrong(i.F)){
            alpha.insert(i.F);
        }
    }
    set<ll>beta;
    for(auto i:alpha){
        rep(j,0,10){
            if(i*10+j<1e14 && isPrime(i*10+j)){
                beta.insert(i*10+j);
            }
        }
    }
    cout<<accumulate(all(beta),0ll);
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
