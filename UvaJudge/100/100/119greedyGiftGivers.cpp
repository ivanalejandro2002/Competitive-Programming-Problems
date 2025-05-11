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
void solve(int n){
    map<string,int> traductor;
    map<int,string> inv;
    string nombre,destino;

    vll dinero(n+1);
    fore(i,1,n){
        cin>>nombre;
        traductor[nombre] = i;
        inv[i] = nombre;
    }

    ll cuantos,aPagar;
    fore(i,1,n){
        cin>>nombre>>aPagar>>cuantos;
        if(aPagar == 0 || cuantos == 0){
            while(cuantos--)cin>>destino;
            continue;
        }
        dinero[traductor[nombre]]+=aPagar%cuantos-aPagar;

        aPagar/=cuantos;

        fore(i,1,cuantos){
            cin>>destino;
            dinero[traductor[destino]]+=aPagar;
        }
    }

    fore(i,1,n){
        cout<<inv[i]<<" "<<dinero[i]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    bool hecho = 0;
    while(cin>>n){
        if(hecho)cout<<"\n";
        hecho = 1;
        solve(n);
    }
}