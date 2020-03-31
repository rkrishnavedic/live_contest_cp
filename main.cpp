//#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define KR1shna
#include "Header.h"
#endif

#define ll long long
#define fori(n) for(long long i=0;i<n;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define sp(n) setprecision(n)
#define mkp make_pair
#define mkt make_tuple
#define pi 3.14159265358979323846264
#define d7 1000000007
#define l7 998244353

using namespace std;

bool isPrime(long long k){
    if(k<=1){return false;}
    if(k==2){return true;}
    if(k%2==0){return false;}
    long long i = 3;
   while (i*i <= k) {if (k % i == 0) {return false;}i += 2;}
return true;
}

ll binomialCoeff(ll n, ll k){
    ll C[n + 1][k + 1];ll i, j;
    for (i = 0; i <= n; i++){
        for (j = 0; j <= min(i, k); j++){
            if (j == 0 || j == i){C[i][j] = 1;}
            else{C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);}}}
    return C[n][k];
 }

ll gcd(ll a, ll b){if (b == 0)
        return a;return gcd(b, a % b);}

ll expmod(ll n,ll k,ll m){
    ll ans;
    ans=1;
    fori(k){
        ans=(ans*n)%m;
    }
    return ans;
}
//define temp-functions below


//some definitions and global variables
vector<ll> primes;
void storePrime(ll n){
    fori(n){
        if(isPrime(i+1)&&(n%(i+1)==0)){primes.push_back(i+1);}
    }
}

void srihrg(){
    //code starts
    
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll sump=0;
    fori((k+1)/2){
        ll sum=0;
        map<char,ll> mp;
        //ll df=0;
        vector<char> v;
        vector<char> vb(n,'0');
        for(ll j=i;j<n;j+=k){
            if(mp[s[j]]==0){v.push_back(s[j]);}
            if(vb[j]=='0') {mp[s[j]]++;sum++;vb[j]='1';}
        }
        for(ll j=n-1-i;j>=0;j-=k){
            if(mp[s[j]]==0){v.push_back(s[j]);}
            if(vb[j]=='0') {mp[s[j]]++;sum++;vb[j]='1';}
        }
        ll mx=0;
        forj(v.size()){
            mx=max(mp[v[j]],mx);
        }
        
        sump+=sum-mx;
    }
    
    //cout<<ui<<" ";
    cout<<sump;
    //code ends
}

int main(int argc, const char * argv[]) {
#ifdef KR1shna
    cout<<"||ओ३म्||"<<endl;
#endif
 //make cin/cout faster
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);cout.tie(NULL);
// code now

    ll t=1;
    cin>>t;
    while(t--){
        
        srihrg();
        
        cout<<endl;
    }
    
//code ends
    return 0;
}
