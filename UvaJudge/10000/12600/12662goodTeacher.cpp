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

pair<int,string> conocido(int n,vector<string> &noms, int pos, int dir){
    while(pos<=n && pos>0){
        if(noms[pos]!="?")return {pos,noms[pos]};
        pos+=dir;
    }
    return {-1,""};
}

void solve(){
    int n;
    cin>>n;

    vector<string> noms(n+1);
    fore(i,1,n)cin>>noms[i];

    int m,k;
    cin>>m;
    while(m--){
        cin>>k;
        if(noms[k]!="?"){
            cout<<noms[k]<<"\n";
            continue;
        }

        auto [posIzq,nombreIzq] = conocido(n,noms,k,-1);
        auto [posDer,nombreDer] = conocido(n,noms,k,1);

        if(posIzq >0 && posDer>0){
            if(abs(posIzq - k) == abs(posDer-k)){
                cout<<"middle of "<<nombreIzq<<" and "<<nombreDer<<"\n";
                continue;
            }
            if(abs(posIzq-k)>abs(posDer-k)){
                fore(i,k,posDer-1){
                    cout<<"left of ";
                }
                cout<<nombreDer<<"\n";
            }else{
                fore(i,posIzq,k-1){
                    cout<<"right of ";
                }
                cout<<nombreIzq<<"\n";
            }
        }else{
            if(posDer>0){
                fore(i,k,posDer-1){
                    cout<<"left of ";
                }
                cout<<nombreDer<<"\n";
            }else{
                fore(i,posIzq,k-1){
                    cout<<"right of ";
                }
                cout<<nombreIzq<<"\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}