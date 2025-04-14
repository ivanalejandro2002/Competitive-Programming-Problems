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
const ll MOD = 1e9+7;
void solve(){
    int n,m,k;
    vll dados(8);
    cin>>n;
    ll actual = 0;
    ll acumulado = 0;
    ll aux;
    int indice = 1;
    for(int i=1;i<=n;i++){
        aux = dados[indice];
        dados[indice]=acumulado;
        if(i<=6){
            dados[indice]++;
            if(dados[indice]>=MOD){
                dados[indice]-=MOD;
            }
        }
        acumulado-=aux;
        if(acumulado<0)acumulado+=MOD;
        acumulado+=dados[indice];
        if(acumulado>=MOD)acumulado-=MOD;
        indice++;
        if(indice==6)indice=0;
    }
    cout<<dados[n%6]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}