#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
#define fore(V,I,F) for(int V=I;V<=F;V++)
typedef long long int ll;
typedef long double ld;
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
    int n,k;
    set<int> resueltos[3];
    fore(sel,0,2){
        cin>>n;
        fore(i,1,n){
            cin>>k;
            resueltos[sel].insert(k);
        }
    }

    vector<vector<int> > unicos(3);

    fore(sel,0,2){
        for(int z: resueltos[sel]){
            if(!resueltos[(sel+1)%3].count(z) && !resueltos[(sel+2)%3].count(z))
                unicos[sel].pb(z);
        }
    }

    int mayor = 0;
    fore(sel,0,2)mayor = max(mayor, (int)unicos[sel].size());

    fore(sel,0,2){
        if(mayor == unicos[sel].size()){
            cout<<sel+1<<" "<<mayor;
            for(int z: unicos[sel])cout<<" "<<z;
            cout<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    fore(i,1,t){
        cout<<"Case #"<<i<<":\n";
        solve();
    }
}