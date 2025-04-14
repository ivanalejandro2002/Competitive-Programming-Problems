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
void solve(){
    int n,m,k,u,v;
    cin>>n>>m;
    vi indegree(n+1);
    vvi mapa(n+1);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        indegree[v]++;
        mapa[u].pb(v);
    }

    queue<int> cola;
    vb visto(n+1);
    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            visto[i] = 1;
            cola.push(i);
        }
    }

    vi solucion;
    while(!cola.empty()){
        k = cola.front();
        cola.pop();
        solucion.pb(k);
        for(int z:mapa[k]){
            indegree[z]--;
            if(!indegree[z]){
                visto[z] = 1;
                cola.push(z);
            }
        }
    }

    if(solucion.size()!=n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(int z:solucion){
        cout<<z<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}