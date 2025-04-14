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

void busca(int nodo, vvi &mapa, vb &visto){
    visto[nodo] = 1;
    for(int z:mapa[nodo]){
        if(visto[z])continue;
        busca(z,mapa,visto);
    }
}

int solve(){
    char n;
    char u,v;
    cin>>n;
    int N = (int)n-'A'+1;
    vvi mapa(N+1);

    string s;
    getline(cin,s);
    bool terminado = 0;
    while(!terminado){
        getline(cin,s);
        if(s.size()==0)break;
        u = s[0];
        v = s[1];
        mapa[(int)u-'A'+1].pb((int)v-'A'+1);
        mapa[(int)v-'A'+1].pb((int)u-'A'+1);
    }
    vb visto(N+1);
    int sol = 0;
    fore(i,1,N){
        if(visto[i])continue;
        sol++;
        busca(i,mapa,visto);
    }

    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    bool hecho = 0;
    string w;
    getline(cin,w);
    getline(cin,w);
    while(n--){
        if(hecho)cout<<"\n";
        hecho = 1;
        cout<<solve()<<"\n";
    }
}