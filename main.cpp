#define KR1shna

#ifdef KR1shna
#include "Header.h"
#else
#include <bits/stdc++.h>
#endif

#define ll long long
#define fori(n) for(long long i=0;i<n;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define forr(i,x,y) for(long long i=x;i<y;i++)
#define sp(n) setprecision(n)
#define mkp make_pair //use tie instead {x,y}=pair_variable to make pair-variable assignment
#define mkt make_tuple //just put {a,b} eqv mkp(a,b) Similar rules for tuple
#define pi 3.14159265358979323846264
#define d7 1000000007
#define l7 998244353
#define en cout<<endl
#define nn cout<<"\n"

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
//Primes using crossMethod..............
ll N=1e5+4;
vector<bool> is_prime(N+1, true);
void validateprime(ll n){
is_prime[0] = is_prime[1] = false;
for (ll i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (ll j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
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

void dfs(ll s, vector<bool> &v, vector<ll> adj[]){
    if(v[s]) return;
    v[s]=true;
    cout<<s+1<<" ";
    for(auto u: adj[s]){
        dfs(u,v,adj);
    }
}

//some definitions and global variables >>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<
vector<ll> primes;
void storePrime(ll n){
    validateprime(n);
    fori(n){
        if(is_prime[i+1]){primes.push_back(i+1);}
    }
}

void srihrg(){
    //code starts
    
    ll n;
    cin>>n;
    ll a[n];
    fori(n){
        cin>>a[i];
    }
    ll cnt=0;
    vector<ll> vs;
    set<ll> st;
    map<ll,ll> mp;
    fori(n){
        ll p=sqrt(a[i]);
        ll c=cbrt(a[i]);
        if(p*p==a[i]){
            ll io=sqrt(p);
            if(io*io==p){st.insert(io);mp[io]+=4;}
            else{st.insert(p);mp[p]+=2;}
        }else{
            if(c*c*c==a[i]){st.insert(c);mp[c]+=3;}
            else{vs.push_back(a[i]);}
        }
    }
    //cout<<vs.size();
   if(vs.size()>0){ vector<ll> vx;
    vector<bool> bvs(vs.size(),false);
    fori(vs.size()-1){
        bool pol=false;
        ll jkl=-1;
        forr(j,i+1,vs.size()){
            if(bvs[j]){continue;}
            ll gx=gcd(vs[i], vs[j]);
            if(gx>1&&gx<vs[i]){
                
                pol=true;jkl=gx;
                mp[jkl]++;st.insert(jkl);
                mp[vs[j]/jkl]++;st.insert(vs[j]/jkl);
                    bvs[j]=true;
            }
        }
        if(pol){
            mp[jkl]++;st.insert(jkl);
            mp[vs[i]/jkl]++;st.insert(vs[i]/jkl);
            bvs[i]=true;
        }
    }
    //cout<<"kl";
    fori(vs.size()){
        if(!bvs[i]){vx.push_back(vs[i]);}
    }
    vector<bool> bvx(vx.size(),false);
    fori(vx.size()){
        for(auto ui: st){
            if(vx[i]%ui==0){
                mp[ui]++;
                mp[vx[i]/ui]++;
                st.insert(vx[i]/ui);
                bvx[i]=true;break;
            }
        }
    }
       map<ll,ll> bs;
       set<ll> st1;
    fori(vx.size()){
        if(!bvx[i]){st1.insert(vx[i]);bs[vx[i]]++;}
    }
       cnt=1;
       //cout<<st1.size();en;
       for(auto gh:st1){
           cnt=(cnt*(bs[gh]+1)*(bs[gh]+1))%l7;
           //cout<<cnt<<" ";
       }
   }
    //en;
    ll ans=1;
    if(cnt!=0){ans=cnt;}
    for(auto gh:st){
        //cout<<gh<<" ";
        ans=(ans*(mp[gh]+1))%l7;
    }
    //en;
    cout<<ans;
    
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
    //cin>>t;
    ll nt=1;
    while(t--){
        //cout<<"Case #"<<nt<<": ";
        srihrg();
        nt++;
        cout<<endl;
    }
    
//code ends
    return 0;
}
