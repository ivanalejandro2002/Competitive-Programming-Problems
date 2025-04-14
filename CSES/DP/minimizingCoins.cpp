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
void dpsea(vpii &DP,vi &monedas){
    DP[0] = {0,1};
    for(int i=0;i<DP.size();i++){
        if(!DP[i].second)continue;
        for(int z:monedas){
            if(i+z<DP.size()){
                DP[i+z].se = 1;
                DP[i+z].fi = min(DP[i+z].fi,DP[i].fi+1);
            }
        }
    }
}
void solve(){
    int n,m,k;
    cin>>n>>m;
    vpii DP(m+1,{INT_MAX,0});
    vi monedas;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==0)continue;
        monedas.pb(k);
    }
    dpsea(DP,monedas);
    if(!DP[m].se){
        cout<<"-1\n";
        return;
    }
    cout<<DP[m].fi<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}