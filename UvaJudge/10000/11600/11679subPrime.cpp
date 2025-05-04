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

string solve(int b, int n){
    vi dinero(b+1);
    fore(i,1,b)cin>>dinero[i];
    int u,v,c;
    while(n--){
        cin>>u>>v>>c;
        dinero[u]-=c;
        dinero[v]+=c;
    }

    fore(i,1,b)if(dinero[i]<0)return "N";
    return "S";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int b,n;
    do{
        cin>>b>>n;
        if(b==0 && n==0)break;
        cout<<solve(b,n)<<"\n";
    }while(b!=0 || n!=0);
}