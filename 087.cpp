#include <bits/stdc++.h>
#define N 8000
#define maxN 50000000
using namespace std;
bool mysieve[N];

void primesieve() {												//returns pointer to Sieve of Eratosthenes of size N
	memset(mysieve,true,sizeof mysieve);
	mysieve[0] = false;
	mysieve[1] = false;
	for(int i = 2; i * i <= N; ++i) {
		if(mysieve[i] == true) {
			for(int j = i * i; j <= N ;j += i)
				mysieve[j] = false;
		}
	}
}

signed main()
{
    primesieve();
    set<int>p;
    for(int i=0;i*i<maxN;i++){
        if(mysieve[i]){
            int sqi=i*i;
            for(int j=0;sqi+j*j*j<maxN;j++){
                if(mysieve[j]){
                    int cubej=sqi+j*j*j;
                    for(int k=0;k*k*k*k+cubej<=maxN;k++){
                        if(mysieve[k]){
                            p.insert(cubej+k*k*k*k);
                        }
                    }
                }
            }
        }
    }
    cout<<p.size();
    return 0;
}
