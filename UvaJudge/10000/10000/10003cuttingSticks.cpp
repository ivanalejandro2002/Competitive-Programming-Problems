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

int dpsea(int l, int r, vvi &dp, vi &dists){
    if(r-l == 1){
        dp[l][r] = abs(dists[r]-dists[l]);
        return abs(dists[r]-dists[l]);
    }
    int mejor = INT_MAX;
    fore(i,l+1,r-1){
        int izq,der;
        if(dp[l][i]==INT_MAX)dp[l][i] = dpsea(l,i,dp,dists);
        if(dp[i][r]==INT_MAX)dp[i][r] = dpsea(i,r,dp,dists);

        //cout<<l<<","<<r<<"::"<<i<<"=="<<izq<<","<<der<<"\n";
        izq = dp[l][i];
        der = dp[i][r];

        mejor = min(mejor, izq+der);
    }
    return mejor + abs(dists[r]-dists[l]);
}

void solve(int l){
    int n,m,k;
    cin>>n;
    vi dists = {0};
    fore(i,1,n){
        cin>>k;
        dists.pb(k);
    }
    dists.pb(l);
    /*fore(i,0,n+1){
        cout<<dists[i]<<",";
    }
    cout<<"\n";*/
    vvi dp(n+2,vi(n+2,INT_MAX));

    cout<<"The minimum cutting is "<<dpsea(0,n+1,dp,dists)-l<<".\n";

    /*fore(i,0,n+1){
        fore(j,0,n+1){
            cout<<dp[i][j]<<",";
        }
        cout<<"\n";
    }*/
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int l,n;
    do{
        cin>>l;
        if(l==0)break;
        solve(l);
    }while(l>0);
}