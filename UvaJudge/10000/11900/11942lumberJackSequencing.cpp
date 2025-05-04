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

string solve(){
    vi datos(10);
    fore(i,0,9)cin>>datos[i];
    bool mayor = 1,menor = 1;

    fore(i,1,9)if(datos[i]<datos[i-1])mayor = 0;
    fore(i,1,9)if(datos[i]>datos[i-1])menor = 0;

    if(mayor || menor)return "Ordered";
    return "Unordered";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<"Lumberjacks:\n";
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}