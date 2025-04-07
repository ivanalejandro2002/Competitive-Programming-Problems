#include <bits/stdc++.h>
#include <fstream>
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

bool propaga(vi &log, int idx, int v){
    //cout<<idx<<":)\n";
    if(v==-1)return true;
    if(log[idx]!=-1)return log[idx]==v;
    log[idx] = v;
    //cout<<idx<<"="<<v<<"\n";
    return propaga(log,idx-1,v-1);
}

bool cambia(vi &log,int n){
    fore(i,1,n){
        if(log[i]!=-1){
            if(!propaga(log,i-1,log[i]-1))return false;
        }
    }
    return true;
}
void solve(){
    int n,m,k;
    ifstream fin;
    ofstream fout;
    fin.open("taming.in");
    fout.open("taming.out");
    fin>>n;
    vi log(n+1);

    fore(i,1,n)fin>>log[i];
    if(log[1]>=1){
        fout<<"-1\n";
        return;
    }
    log[1]=0;

    if(!cambia(log,n)){
        fout<<"-1\n";
        return;
    }

    int sol = 0;
    int menor,mayor;
    menor = mayor = 0;
    bool seCuenta = 1;
    bool paridad = 0;
    bool aumentado = 0;

    fore(i,1,n){
        if(log[i]==0){
            if(aumentado)menor--;
            aumentado = 0;
            sol++;
            seCuenta = 1;
            paridad = 0;
            continue;
        }
        if(log[i]==-1){
            if(seCuenta){
                menor++;
                seCuenta = 0;
                aumentado = 1;
            }
            mayor++;
        }else{
            seCuenta = 1;
            paridad = 0;
            aumentado = 0;
        }
    }
    if(log[n] == -1)menor--;

    fout<<sol+menor<<" "<<sol+mayor<<"\n";
    
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}