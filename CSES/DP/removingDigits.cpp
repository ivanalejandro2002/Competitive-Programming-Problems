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
struct nodo{
    bool existe;
    int cantidad;
};
int DPsea(int n){
    vector<nodo> DP(n+1,{0,INT_MAX});
    int w = 0;
    int x;
    DP[n] = {1,0};
    for(int i=n;i>0;i--){
        if(!DP[i].existe)continue;
        w = i;
        while(w>0){
            x = w%10;
            w/=10;
            if(x==0)continue;
            DP[i-x].existe = 1;
            DP[i-x].cantidad = min(DP[i-x].cantidad,DP[i].cantidad+1);
        }
    }
    return DP[0].cantidad;
}
void solve(){
    int n,m,k;
    cin>>n;
    cout<<DPsea(n);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}