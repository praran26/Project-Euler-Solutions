#include <bits/stdc++.h>

using namespace std;
int a[10];
int digitfact(int n){
    int ans=0;
    while(n!=0){
        int digit=n%10;
        ans+=a[digit];
        n/=10;
    }
    return ans;
}
int main()
{
    a[0]=1;
    for(int i=1;i<10;i++){
        a[i]=i*a[i-1];
    }
    map<int,int>mainmap;
    for(int i=1;i<=1000000;i++){
        if(mainmap[i]>0)continue;
        else{
            map<int,int>temp;
            int pos=1;
            int alpha=i;
            map<int,int>rev;
            while(rev[alpha]==0 && mainmap[alpha]==0){
                temp[pos]=alpha;
                rev[alpha]=pos;
                pos+=1;
                alpha=digitfact(alpha);
            }
            if(mainmap[alpha]!=0){
                int beta=mainmap[alpha];
                for(int j=1;j<pos;j++){
                    mainmap[temp[j]]=beta+pos-j;
                }
            }
            else{
                int beta=pos-rev[alpha];
                for(int j=1;j<pos-beta;j++){
                    mainmap[temp[j]]=pos-j;
                }
                for(int j=pos-beta;j<pos;j++){
                    mainmap[temp[j]]=beta;
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=1000000;i++){
        if(mainmap[i]==60)ans++;
    }
    cout<<ans;
    return 0;
}
