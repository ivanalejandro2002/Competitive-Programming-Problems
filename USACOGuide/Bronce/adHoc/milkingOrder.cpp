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

bool checa(vi &ocupabilidad, vi &orden,set<int> &ordenados ,int pos,set<int> &tocados){
    set<int> checados;
    int z = 0;
    for(int i=1;i<ocupabilidad.size();i++){
        if(i==pos){
            if(ocupabilidad[i]!=0 && ocupabilidad[i]!=1)return false;
            if(!ordenados.count(1))continue;
            if(checados.count(1))continue;
            if(orden[z]==1){
                z++;
                continue;
            }
            return false;
        }
        if(!ocupabilidad[i]){
            if(z<orden.size()){
                if(!tocados.count(orden[z])){
                    checados.insert(orden[z]);
                    z++;
                }
            }
        }else{
            if(!ordenados.count(ocupabilidad[i]))continue;
            if(checados.count(ocupabilidad[i]))continue;
            if(orden[z]==ocupabilidad[i]){
                z++;
                continue;
            }
            return false;
        }
    }
    return true;
}
int bruta(int n, vi &orden, vpii &tocs){
    vi ocupabilidad(n+1);   
    set<int> ordenados;
    set<int> tocados;
    for(int z:orden)ordenados.insert(z);
    for(auto z:tocs){
        tocados.insert(z.fi);
        ocupabilidad[z.se] = z.fi;
        if(z.fi == 1)return z.se;
    }

    for(int i=1;i<=n;i++){
        bool res = checa(ocupabilidad,orden,ordenados,i,tocados);
        if(res)return i;
    }
    return -1;
}
void solve(){
    int n,m,k;

    ifstream fin;
    ofstream fout;
    fin.open("milkorder.in");
    fout.open("milkorder.out");

    fin>>n>>m>>k;
    vi orden(m);

    fore(i,0,m-1)fin>>orden[i];
    
    vpii tocs(k);
    fore(i,0,k)fin>>tocs[i].fi>>tocs[i].se;

    fout<<bruta(n,orden,tocs);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}