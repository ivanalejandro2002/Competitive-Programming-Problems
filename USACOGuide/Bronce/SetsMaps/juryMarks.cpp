#include <bits/stdc++.h>
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

void solve(){
    ll n,m,k;
    cin>>n>>k;

    vll datos(n+1);
    fore(i,1,n)cin>>datos[i];

    vll acum(n+1);
    fore(i,1,n)acum[i]=acum[i-1]+datos[i];
    set<ll> usados;
    vll extra(1);
    fore(i,1,n){
        if(usados.count(acum[i]))continue;
        usados.insert(acum[i]);
        extra.pb(acum[i]);
    }
    n = extra.size()-1;

    vll puntos(k+1);
    fore(i,1,k)cin>>puntos[i];

    unordered_map<ll,ll> origenes;
    int cont = 0;
    ll actual;
    fore(i,1,k){
        m = puntos[i];
        fore(j,1,n){
            origenes[m-extra[j]]++;
        }
    }
    for(auto z:origenes)if(z.se == k)cont++;
    /*for(auto z:origenes){
        cout<<z.fi<<","<<z.se<<"\n";
    }*/
    cout<<cont<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}