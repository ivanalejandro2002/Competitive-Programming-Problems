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

string solve(ll n){
    int g,k;
    cin>>g;

    set<int> tomados;

    fore(i,1,n){cin>>k;tomados.insert(k);}
    bool posible = 1;
    int m,pt;
    while(g--){
        cin>>m>>pt;
        int cont = 0;
        while(m--){
            cin>>k;
            cont+=tomados.count(k);
        }
        if(cont<pt)posible = 0;
    }

    if(posible)return "yes";
    return "no";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    do{
        cin>>n;
        if(n==0)break;
        cout<<solve(n)<<"\n";
    }while(n>=0);
}