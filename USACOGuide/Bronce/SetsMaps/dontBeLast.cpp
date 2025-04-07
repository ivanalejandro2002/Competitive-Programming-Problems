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

void solve(){
    ifstream fin;
    ofstream fout;

    fin.open("notlast.in");
    fout.open("notlast.out");

    map<string,int> datos = {
        {"Bessie", 0},
        {"Elsie",0},
        {"Daisy",0},
        {"Gertie",0},
        {"Annabelle",0},
        {"Maggie",0},
        {"Henrietta",0},
    };

    int n;
    fin>>n;
    string vaca;
    int leche;
    while(n--){
        fin>>vaca>>leche;
        datos[vaca]+=leche;
    }
    map<int,vector<string> > mapa;
    map<int,vector<string> >::iterator it;
    for(auto z: datos){
        mapa[z.se].pb(z.fi);
    }

    it = mapa.begin();
    it++;
    if(it->second.size()==1){
        fout<<it->second[0]<<"\n";
    }else{
        fout<<"Tie\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}