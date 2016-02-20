#include <bits/stdc++.h>
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
#define DEBUG true
using namespace std;
template <class X>
void input(vector<X>&a,int N){
    X temp;
    rep(i,0,N){
        cin>>temp;
        a.push_back(temp);
    }
}
int N=100000000;
bool* mysieve=new bool[100000000];
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
void solve(){
    cout<<"Filling up sieve..."<<endl;
    primesieve();
    cout<<"Finished up filling..."<<endl;
    ll ans=1;
    cout<<"Beginning loop..."<<endl;
    for(int j=2;j<100000000-1;j+=2){
        if(mysieve[j+1]){
            bool flag=true;
            for(int k=2;k<sqrt(j)+2;k++){
                if(j%k!=0)continue;
                if(mysieve[j/k+k])continue;
                else{
                    flag=false;
                    break;
                }
            }
            if(flag)ans+=j;
        }
    }
    cout<<"Loop finished..."<<endl;
    cout<<"The answer is: "<<ans<<endl;
    cout<<"Cleaning up sieve..."<<endl;
    free(mysieve);
    cout<<"Finished up cleaning..."<<endl;
}

int main(){
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
