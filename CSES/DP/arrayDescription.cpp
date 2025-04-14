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
int DPsea(int n, int m, vi &nums){
    vvll DP(2, vll(m+2));
    if(nums[0]==0){
        for(int i=1;i<=m;i++)DP[0][i]=1;
    }else{
        DP[0][nums[0]]=1;
    }

    /*for(int i=1;i<=m;i++){
        cout<<DP[0][i]<<",";
    }
    cout<<"\n";*/

    int sol = 0;
    int ncosto;
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            DP[i%2][j]=0;
            if(j==nums[i] || nums[i]==0){
                DP[i%2][j] = (DP[(i+1)%2][j-1] + DP[(i+1)%2][j] + DP[(i+1)%2][j+1])%mod;
            }
        }
        /*for(int k=1;k<=m;k++){
            cout<<DP[i%2][k]<<",";
        }
        cout<<"\n";*/
    }
    for(int i=1;i<=m;i++){
        sol+=DP[(n+1)%2][i];
        sol%=mod;
    }
    return sol;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vi nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<DPsea(n,m,nums);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}