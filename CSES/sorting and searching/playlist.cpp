#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
void solve(){
    int n,m,k;
    cin>>n;
    vi canciones(n);
    for(int i=0;i<n;i++)cin>>canciones[i];
    int ini,fin;
    ini = 0;
    fin = -1;
    bool parar = 0;
    int maximo = 0;
    set<int> datos;
    while(ini<n){
        while(!parar && fin<n){
            fin++;
            if(datos.count(canciones[fin]))parar=1;
            datos.insert(canciones[fin]);
        }
        maximo = max(fin-ini,maximo);
        while(datos.count(canciones[fin])){
            datos.erase(canciones[ini]);
            ini++;
        }
        parar = 0;
        datos.insert(canciones[fin]);
        maximo = max(fin-ini+1,maximo);
    }
    maximo = max(fin-ini,maximo);
    cout<<maximo<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}