#include<bits/stdc++.h>
#define ll          long long int
#define pb          emplace_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define Max(a,b)    ((a)>(b)?(a):(b))
#define Min(a,b)    ((a)<(b)?(a):(b))
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<(b);i+=1)
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
using namespace std;

void solve(){
    ll x[10][40];
    memset(x,0,sizeof x);
    rep(i,1,5){
        x[1][i]=1;
    }
    rep(i,2,10){
        rep(j,1,40){
            rep(k,1,5){
                if(k+j<40)x[i][k+j]+=x[i-1][j];
            }
        }
    }
    ll y[7][40];
    memset(y,0,sizeof y);
    rep(i,1,7){
        y[1][i]=1;
    }
    rep(i,2,7){
        rep(j,1,40){
            rep(k,1,7){
                if(k+j<40)y[i][k+j]+=y[i-1][j];
            }
        }
    }
    ll ans=0;
    ll dena=accumulate(x[9],x[9]+40,0LL),denb=accumulate(y[6],y[6]+40,0LL);
    rep(i,0,40){
        rep(j,0,40){
            if(i>j)ans+=x[9][i]*y[6][j];
        }
    }
    cout<<fixed<<setprecision(9)<<(long double)ans/(dena*denb);
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
