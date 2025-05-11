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
const int MAXN = 30000;

vll dp(MAXN+61);
void dpsea(){
    vll monedas = {1,5,10,25,50};
    dp[0] = 1;
    for(int z:monedas){
        fore(i,0,MAXN){
            dp[i+z]+=dp[i];
        }
    }
}

void solve(int n){
    if(dp[n]==1){
        cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
        return;
    }
    cout<<"There are "<<dp[n]<<" ways to produce "<<n<<" cents change.\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    dpsea();
    while(cin>>n)
        solve(n);
}