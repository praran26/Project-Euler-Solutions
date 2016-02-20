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
bool isPrime(int N) {													//determines if the argument is prime or not (deterministic)
	if(N<2)return false;
	if(N<4)return true;
	if((N&1)==0)return false;
	if(N%3==0)return false;
	int curr=5;
	while (curr<=sqrt(N)){
		if(N%curr==0)return false;
		curr+=2;
		if(N%curr==0)return false;
		curr+=4;
	}
	return true;
}

void solve(){
    int N=10001;
    int curr=1;
    while(N){
        curr++;
        if(isPrime(curr)){
            N--;
        }
    }
    cout<<curr;
}

int main(){
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
