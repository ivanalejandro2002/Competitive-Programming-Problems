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
int DPsea(vector<string> &mapa){
    vvll DP(mapa.size()+1,vll(mapa[0].size()+1));
    if(mapa[0][0]!='*')
        DP[0][0] = 1;
    for(int i=0;i<mapa.size();i++){
        for(int j=0;j<mapa[0].size();j++){
            DP[i][j]%=mod;
            if(j<mapa[0].size()-1 && mapa[i][j+1]!='*')
                DP[i][j+1] +=DP[i][j];
            if(i<mapa.size()-1 && mapa[i+1][j]!='*')
                DP[i+1][j] +=DP[i][j];
        }
    }
    return DP[mapa.size()-1][mapa[0].size()-1];
}
void solve(){
    int n,m,k;
    cin>>n;
    vector<string> mapa(n);
    for(int i=0;i<n;i++){
        cin>>mapa[i];
    }
    cout<<DPsea(mapa);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}