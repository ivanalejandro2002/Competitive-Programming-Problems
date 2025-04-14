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
vector<pair<ll,ll> > extras;
void dpsea(vpii &DP,vi &monedas){
    DP[0] = {1,1};
    extras.resize(DP.size());
    for(int zi:monedas){
        for(int i=0;i<DP.size();i++){
            if(!DP[i].second)continue;
            if(extras[i].second)continue;
            int acum = zi;
            int adicional = DP[i].fi;
            while(i+acum<DP.size()){
                extras[i+acum].se = 1;
                extras[i+acum].fi += adicional;
                adicional+=DP[i+acum].fi;
                if(adicional>=MOD)adicional-=MOD;
                if(extras[i+acum].fi>=MOD)extras[i+acum].fi-=MOD;
                acum+=zi;
            }
        }
        for(int j=0;j<DP.size();j++){
            if(!extras[j].se)continue;
            DP[j].se = 1;
            DP[j].fi+=extras[j].fi;
            if(DP[j].fi>=MOD)DP[j].fi-=MOD;
            extras[j]={0,0};
        }
    }
}
void solve(){
    int n,m,k;
    cin>>n>>m;
    vpii DP(m+1,{0,0});
    vi monedas;
    set<int> hechos;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==0)continue;
        if(hechos.count(k))continue;
        hechos.insert(k);
        monedas.pb(k);
    }
    sort(all(monedas));
    reverse(all(monedas));
    dpsea(DP,monedas);
    cout<<DP[m].fi<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}