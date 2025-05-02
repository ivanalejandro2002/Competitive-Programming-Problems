#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
#define fore(V,I,F) for(int V=I;V<=F;V++)
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

string solve(){
    int n,l;
    cin>>n>>l;
    vi mesa(n);
    vi limite(n);

    fore(i,0,n-1)cin>>mesa[i];
    fore(i,0,n-1)cin>>limite[i];

    bool posible = 1;
    fore(i,0,n-1)if(mesa[i]>limite[i])posible=0;

    int suma = 0;
    fore(i,0,n-1)suma+=mesa[i];

    if(l<suma)posible = 0;

    return (posible)?"Yes":"No";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    fore(i,1,t){
        cout<<"Case "<<i<<": "<<solve()<<"\n";
    }
}