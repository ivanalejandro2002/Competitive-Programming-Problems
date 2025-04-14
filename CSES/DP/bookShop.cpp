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
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
const ll mod = 1e9+7;
struct nodo{
    bool existe;
    int valor;
};
int DPsea(int n, int x, vi &costos, vi &hojas){
    vector<vector<nodo> > DP(2, vector<nodo>(x+2));
    DP[0][0] = {1,0};

    int sol = 0;
    int ncosto;
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            if(!DP[i%2][j].existe)continue;
            DP[(i+1)%2][j].existe = 1;
            sol = max(sol,DP[i%2][j].valor);
            DP[(i+1)%2][j].valor = max(DP[i%2][j].valor,DP[(i+1)%2][j].valor);
            ncosto = j + costos[i];
            if(ncosto >x)continue;
            DP[(i+1)%2][ncosto].existe = 1;
            DP[(i+1)%2][ncosto].valor = max(DP[(i+1)%2][ncosto].valor,DP[i%2][j].valor+hojas[i]);
            sol = max(sol,DP[(i+1)%2][ncosto].valor);
        }
    }
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            cout<<DP[i][j].valor<<",";
        }
        cout<<"\n";
    }*/
    return sol;
}
void solve(){
    int n,x;
    cin>>n>>x;
    vi costos(n+1);
    vi hojas(n+1);
    for(int i=0;i<n;i++){
        cin>>costos[i];
    }

    for(int i=0;i<n;i++){
        cin>>hojas[i];
    }
    cout<<DPsea(n,x,costos,hojas);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}