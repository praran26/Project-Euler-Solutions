#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
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
#define N 10000000
using namespace std;
bool *mysieve=new bool[N+1];
ll *eulerPhi = new ll[N+1];
double *ans=new double[N+1];
void primesieve() {
	for(int i = 0; i <= N;++i) {
		mysieve[i] = true;
	}
	mysieve[0] = false;
	mysieve[1] = false;
	for(int i = 2; i * i <= N; ++i) {
		if(mysieve[i] == true) {
			for(int j = i * i; j <= N ;j += i)
				mysieve[j] = false;
		}
	}
}
void eulerSieve(){
	for (int i = 0; i <= N; i++)
		eulerPhi[i] = i;
	for(int i=1;i<=N;i++){
		if(mysieve[i]){
			for (int j = i; j <= N; j += i)
				eulerPhi[j] -= eulerPhi[j] / i;
		}
	}
}
void solve(){
    primesieve();
    eulerSieve();
    rep(i,2,N){
        string num="";
        int j=i;
        while(j){
            num.pb(j%10+'0');
            j/=10;
        }
        string x="";
        j=eulerPhi[i];
        while(j){
            x.pb(j%10+'0');
            j/=10;
        }
        sort(all(x));
        sort(all(num));
        if(x!=num)ans[i]=999999999;
        else ans[i]=(i*1.0)/eulerPhi[i];
    }
    int pos=min_element(ans+2,ans+N)-ans;
    cout<<pos;
}


int main()
{
    solve();
    return 0;
}
