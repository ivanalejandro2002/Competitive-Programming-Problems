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
void busca(int n, vvll &d){
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i][k] < LLONG_MAX && d[k][j] < LLONG_MAX)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
}
void solve(){
    ll n,m,k,u,v,q;
    cin>>n>>m>>q;
    vvll mapa(n+1,vll(n+1,LLONG_MAX));
    for(int i=1;i<=n;i++)mapa[i][i] = 0;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>k;
        mapa[u][v] = min(mapa[u][v],k);
        mapa[v][u] = min(mapa[v][u],k);
    }

    busca(n,mapa);

    while(q--){
        cin>>u>>v;
        if(mapa[u][v]>=LLONG_MAX){
            cout<<"-1\n";
            continue;
        }
        cout<<mapa[u][v]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}