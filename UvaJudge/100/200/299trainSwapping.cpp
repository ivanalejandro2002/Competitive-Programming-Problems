#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
#define fore(V,I,F) for(int V=I;V<=F;V++)
typedef long long int ll;
typedef long long int ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

void update(vi &FT, int x, int v){
    while(x>0){
        FT[x]+=v;
        x-=LSOne(x);
    }
}

int query(vi &FT, int x){
    int sol = 0;
    while(x<FT.size()){
        sol+=FT[x];
        x+=LSOne(x);
    }
    return sol;
}

void solve(){
    int n;
    cin>>n;

    vi FT(n+1);
    
    vi trenes(n+1);
    fore(i,1,n)cin>>trenes[i];

    vi posTrenes(n+1);
    fore(i,1,n)posTrenes[trenes[i]] = i;
    
    int s = 0;
    int rp = 0;
    fore(i,1,n){
        rp = posTrenes[i]+query(FT,posTrenes[i]);
        s+=rp-i;
        update(FT,posTrenes[i],1);
    }

    cout<<"Optimal train swapping takes "<<s<<" swaps.\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}