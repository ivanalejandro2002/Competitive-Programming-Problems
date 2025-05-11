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

void dfs(int nodo,vvi &mapa, vb &visto){
    if(visto[nodo])return;
    visto[nodo] = 1;
    for(int z:mapa[nodo])dfs(z,mapa,visto);
}

void solve(int n){
    vvi mapa(n+1);
    vb visto;
    int u,v;
    do{
        cin>>u;
        if(u==0)break;
        do{
            cin>>v;
            if(v==0)break;
            mapa[u].pb(v);
        }while(v!=0);
    }while(u!=0);

    int q;
    cin>>q;
    while(q--){
        cin>>u;
        visto.clear();
        visto.resize(n+1);
        for(int z:mapa[u])
            dfs(z,mapa,visto);
        int cont = 0;
        fore(i,1,n)cont+=(int)!visto[i];
        cout<<cont;
        fore(i,1,n){
            if(!visto[i])cout<<" "<<i;
        }
        cout<<"\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    do{
        cin>>n;
        if(n==0)break;
        solve(n);
    }while(n!=0);
}