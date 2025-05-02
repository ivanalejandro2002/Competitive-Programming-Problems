#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
#define fore(V,I,F) for(int V=I;V<=F;V++)
typedef long long int ll;
typedef long long int ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

ll expbin(ll base, ll exp, ll mod){
    if(exp == 0)return 1;
    ll sol = expbin(base,exp/2,mod);
    sol*=sol;
    sol%=mod;

    if((exp&1))sol*=base;
    sol%=mod;
    return sol;
}

void solve(ll b,ll p, ll m){
    cout<<expbin(b,p,m)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll b,p,m;
    while(cin>>b>>p>>m){
        solve(b,p,m);
    }
}