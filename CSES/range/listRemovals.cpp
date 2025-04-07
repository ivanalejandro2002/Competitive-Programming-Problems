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

vpii corte(vpii &bloques,vi &datos, int k){
    vpii nuevo;
    int w = k;
    int ind = 0;
    while(w>bloques[ind].se-bloques[ind].fi){
        w-=bloques[ind].se-bloques[ind].fi;
        nuevo.pb(bloques[ind]);
        ind++;
    }
    int l,r;
    l = bloques[ind].fi+w-1;
    if(l - bloques[ind].fi >= 1){
        nuevo.pb({bloques[ind].fi,l});
    }
    cout<<datos[l]<<" ";

    r = l+1;
    if(bloques[ind].se != r){
        nuevo.pb({r,bloques[ind].se});
    }
    ind++;
    while(ind<bloques.size()){
        nuevo.pb(bloques[ind]);
        ind++;
    }
    return nuevo;
}
vi reagrupa(vpii &bloques, vi &arr, int &tamano){
    vi nuevo= {0};
    for(auto z:bloques){
        fore(i,z.fi,z.se-1){
            nuevo.pb(arr[i]);
        }
    }
    tamano = nuevo.size()-1;

    return nuevo;
}

void solve(){
    int n,m,k;
    cin>>n;
    vi datos(n+1);
    vpii bloques;

    fore(i,1,n)cin>>datos[i];

    int rn = sqrt(n);
    int tamano = n;

    bloques.pb({1,n+1});

    fore(i,1,n){
        if(i%rn==0){
            datos = reagrupa(bloques,datos,tamano);
            bloques.clear();
            bloques.pb({1,tamano+1});
        }
        /*cout<<"-----------------------------------\n";
        fore(i,1,tamano)cout<<datos[i]<<",";
        cout<<"\n";
        for(auto z:bloques){
            cout<<"{"<<z.fi<<","<<z.se<<"},";
        }
        cout<<"\n";*/
        cin>>k;
        bloques = corte(bloques,datos,k);
    }
    cout<<"\n";
}
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}