#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(S) S.begin(),S.end()
#define LSOne(S) ((S)&(-S))
#define fore(V,L,R) for(int V = L; V<=R;V++)
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
void solve(){
    int n,m,k;
    cin>>n>>k;
    vi arr(n+1);
    fore(i,1,n)cin>>arr[i];
    vpii rangos;
    fore(i,1,n)rangos.pb({i,i});
    map<int,int> iniciado;

    fore(i,1,n){
        if(iniciado.count(arr[i])){
            rangos.pb({iniciado[arr[i]],i});
        }else{
            iniciado[arr[i]] = i;
        }
    }

    sort(all(rangos));
    vpii bloqueos;
    int ultimo = 0;
    for(auto z:rangos){
        if(ultimo<z.fi){
            bloqueos.pb(z);
            ultimo = z.se;
        }else{
            ultimo = max(ultimo,z.se);
            bloqueos.back().se = ultimo;
        }
    }
    /*for(auto z: bloqueos){
        cout<<z.fi<<","<<z.se<<"\n";
    }*/
    int suma = 0;
    for(auto z:bloqueos){
        map<int,int> rep;
        map<int,set<int> > datos;
        map<int,set<int> >::iterator it;
        fore(i,z.fi,z.se){
            if(rep[arr[i]]>0){
                datos[rep[arr[i]]].erase(arr[i]);
            }
            rep[arr[i]]++;
            datos[rep[arr[i]]].insert(arr[i]);
            
        }
        it = datos.end();
        it--;
        suma+=(z.se-z.fi+1)-(it->fi);
        
    }
    cout<<suma<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}