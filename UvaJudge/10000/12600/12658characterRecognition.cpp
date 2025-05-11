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
void solve(){
    int n;
    cin>>n;
    vector<string> mapa(5);
    fore(i,0,4)cin>>mapa[i];

    fore(i,0,n-1){
        if(mapa[1][i*4+1] =='*'){
            cout<<"1";
            continue;
        }
        if(mapa[3][i*4]=='*'){
            cout<<"2";
            continue;
        }
        cout<<"3";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}