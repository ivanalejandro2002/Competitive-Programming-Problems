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

void solve(){
    int n,m,k;
    ifstream fin;
    ofstream fout;
    fin.open("hoofball.in");
    fout.open("hoofball.out");

    fin>>n;
    vi datos(n);
    fore(i,0,n-1)fin>>datos[i];
    sort(all(datos));
    vi restas;
    fore(i,1,n-1){
        restas.pb(datos[i]-datos[i-1]);
    }
    if(restas.size()==0){
        fout<<"1\n";
        return;
    }
    vi cuantasPasan(n);
    vi destino(n);
    fore(i,0,n-1){
        int dizq,dder;
        dizq = dder = INT_MAX;
        if(i>0){
            dizq = restas[i-1];
        }
        if(i<n-1){
            dder = restas[i];
        }

        if(dizq<=dder){
            cuantasPasan[i-1]++;
            destino[i] = i-1;
        }else{
            cuantasPasan[i+1]++;
            destino[i] = i+1;
        }
    }
    int cont = 0;
    /*fore(i,0,n-1){
        cout<<cuantasPasan[i]<<",";
    }
    cout<<"\n";
    fore(i,0,n-1){
        cout<<destino[i]<<",";
    }*/
    fore(i,0,n-1){
        if(!cuantasPasan[i])cont++;
        if(cuantasPasan[i] == 1 && cuantasPasan[destino[i]]==1 && destino[destino[i]]==i && i<destino[i])cont++;
    }
    fout<<cont<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}