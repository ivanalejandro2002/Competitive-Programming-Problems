#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
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
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
struct nodo{
    ll nodo;
    ll t;
}act,nue;
bool operator < (nodo a, nodo b){
    return a.t > b.t;
}

void busca(int o,int n, vector<vpll> &mapa){
    priority_queue<nodo> cola;
    cola.push({o,0});
    vb visto(n+1);
    vll tiempos(n+1);
    while(!cola.empty()){
        do{
            act = cola.top();
            cola.pop();
        }while(!cola.empty() && visto[act.nodo]);

        if(visto[act.nodo])break;

        visto[act.nodo] =1;

        tiempos[act.nodo] = act.t;


        for(pll z:mapa[act.nodo]){
            cola.push({z.fi,act.t+z.se});
        }

    }

    for(int i=1;i<=n;i++){
        cout<<tiempos[i]<<" ";
    }
    cout<<"\n";
}

void solve(){
    ll n,m,k,u,v;
    cin>>n>>m;
    vector<vector<pll> > mapa(n+1);
    for(int i=1;i<=m;i++){
        cin>>u>>v>>k;
        mapa[u].pb({v,k});
    }

    busca(1,n,mapa);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}