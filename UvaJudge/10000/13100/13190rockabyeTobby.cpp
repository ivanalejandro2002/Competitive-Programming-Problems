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
    int tiempo;
    int prioridad;
    int toriginal;
    string nombre;

    const bool operator <(const nodo &otro)const{
        if(tiempo<otro.tiempo)return true;
        if(tiempo>otro.tiempo)return false;
        return prioridad<otro.prioridad;
    }
};

void solve(){
    int n,m,k;
    cin>>n>>k;
    multiset<nodo> orden;
    string s;
    int tiempo;
    fore(i,1,n){
        cin>>s>>tiempo;
        orden.insert({tiempo,i,tiempo,s});
    }
    fore(i,1,k){
        nodo act = *orden.begin();
        orden.erase(orden.find(act));
        cout<<act.tiempo<<" "<<act.nombre<<"\n";
        orden.insert({act.tiempo+act.toriginal,act.prioridad,act.toriginal,act.nombre});
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}