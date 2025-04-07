#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(S) S.begin(),S.end()
#define LSOne(S) ((S)&(-S))
#define fore(V,L,R) for(int V = L; V<=R;V++)
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
void solve(){
    int n,m,k;
    cin>>n;
    n*=2;
    vi kayak(n);
    for(int i=0;i<n;i++)cin>>kayak[i];
    sort(all(kayak));
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vi otro;
            fore(k,0,n-1){
                if(k==i || k == j)continue;
                otro.pb(kayak[k]);
            }

            int mayor = 0;
            for(int i=0;i<otro.size();i+=2){
                mayor += otro[i+1]-otro[i];
            }

            ans = min(ans,mayor);
        }
    }

    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}