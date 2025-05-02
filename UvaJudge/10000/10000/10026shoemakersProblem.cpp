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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

struct nodo{
    ll divisor;
    ll dividendo;
    ll ind;

    bool operator <(nodo &otro){
        ll a,b;
        a = divisor*otro.dividendo;
        b = dividendo*otro.divisor;

        if(a>b)return true;
        if(a<b)return false;

        return ind<otro.ind;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<nodo> cosos(n);
    fore(i,0,n-1){cin>>cosos[i].dividendo>>cosos[i].divisor;cosos[i].ind = i+1;}

    sort(all(cosos));

    bool ant = 0;
    for(auto z:cosos){
        if(ant)cout<<" ";
        ant = 1;
        cout<<z.ind;
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        if(t>=1)cout<<"\n";
    }
}