#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
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
using namespace std;

#define MAXSIEVE 100000000 // All prime numbers up to this in 842 ms, 18348 KB
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000 // sqrt(MAXSIEVE)/2 
char a[MAXSIEVE/16+2]; 

#define isprime(n) (((n)%2)?(a[(n)>>4]&(1<<(((n)>>1)&7))):(n)==2) 

void sieve(){
    int i,j; 
    memset(a,255,sizeof(a)); 
    a[0]=(char)0xFE; 
    for(i=1;i<MAXSQRT;i++){
        if (a[i>>3]&(1<<(i&7))){
            for(j=2*i*(i+1);j<MAXSIEVEHALF;j+=i+i+1) 
                a[j>>3]&=~(1<<(j&7));
        }
    } 
}


inline bool isPrime(ll N) {
    if(N<2)return false;
    if(N<4)return true;
    if((N&1)==0)return false;
    if(N%3==0)return false;
    if(N<MAXSIEVE)return isprime(N);
    ll curr=5;
    while (curr<=sqrt(N)){
        if(N%curr==0)return false;
        curr+=2;
        if(N%curr==0)return false;
        curr+=4;
    }
    return true;
}

inline bool isPrime(string s){
    ll p=0;
    for(auto i:s)
        p=(p*10+i-'0');
    return isPrime(p);
}

vi temp[100000];
void solve(){
    sieve();
    vi primes;
    for(int i=3;i<10000;i+=2){
        if(isPrime(i))primes.emplace_back(i);
    }
    vector<vector<bool>>adj(sz(primes),vector<bool>(sz(primes)));
    for(int i=0;i<sz(primes);i++){
        for(int j=0;j<sz(primes);j++){
            if(isPrime(to_string(primes[i])+to_string(primes[j])) and isPrime(to_string(primes[j])+to_string(primes[i]))){
                adj[i][j]=1;
                temp[i].emplace_back(j);
            }
        }
    }
    for(int i=0;i<sz(primes);i++){
        rep(j,0,sz(temp[i])){
            if(temp[i][j]<i)continue;
            rep(k,j+1,sz(temp[i])){
                rep(l,k+1,sz(temp[i])){
                    rep(m,l+1,sz(temp[i])){
                        if(adj[temp[i][j]][temp[i][k]] and adj[temp[i][l]][temp[i][k]] and adj[temp[i][j]][temp[i][l]] and adj[temp[i][j]][temp[i][m]] and adj[temp[i][l]][temp[i][m]] and adj[temp[i][k]][temp[i][m]]){
                            cout<<primes[i]<<" "<<primes[temp[i][j]]<<" "<<primes[temp[i][k]]<<" "<<primes[temp[i][l]]<<" "<<primes[temp[i][m]]<<endl;
                        }
                    }                    
                }
            }
        }
    }
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