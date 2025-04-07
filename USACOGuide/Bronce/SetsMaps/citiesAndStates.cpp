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
    ll n,m,k;
    ifstream fin;
    ofstream fout;
    fin.open("citystate.in");
    fout.open("citystate.out");

    fin>>n;
    map<pair<ll,ll>,ll> listado;
    string cad,cod;
    vector<pair<ll,ll> > originales;
    ll s = 0;
    while(n--){
        fin>>cad>>cod;
        originales.pb({(int)cad[0]*1000+(int)cad[1],(int)cod[0]*1000+(int)cod[1]});
        if(originales.back().fi == originales.back().se)continue;
        s+=listado[originales.back()];
        listado[{originales.back().se,originales.back().fi}]++;
    }
    fout<<s<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}