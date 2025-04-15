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
const ll mod = 1e9+7;

void solve(int n){
    vector<pair<ll,ll> > coords(n);
    fore(i,0,n-1)cin>>coords[i].fi>>coords[i].se;

    pair<ll,ll> cruz = coords[n/2];
    ll a,b;
    a = b = 0;
    for(auto z: coords){
        if(z.se>cruz.se && z.fi>cruz.fi)a++;
        if(z.se<cruz.se && z.fi<cruz.fi)a++;
        if(z.se>cruz.se && z.fi<cruz.fi)b++;
        if(z.se<cruz.se && z.fi>cruz.fi)b++;
    }

    cout<<a<<" "<<b<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    bool hecho = 0;
    do{
        cin>>n;
        if(n==0)break;
        solve(n);
    }while(n!=0);
}