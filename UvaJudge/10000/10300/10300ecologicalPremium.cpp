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
const ll mod = 1e9+7;

void solve(){
    int n;
    cin>>n;
    ll aux = 0;
    ll a,b,c;
    while(n--){
        cin>>a>>b>>c;
        aux+=a*c;
    }
    cout<<aux<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}