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
    string cad;
    getline(cin,cad);
    
    vi ocurrencias(256);
    int mejor = 0;
    for(int i=0;i<cad.size();i++){
        if(cad[i]>='A' && cad[i]<='Z'){
            cad[i]+='a'-'A';
        }
        if(cad[i]>='a' && cad[i]<='z'){
            ocurrencias[(int)cad[i]]++;
            mejor = max(mejor,ocurrencias[(int)cad[i]]);
        }
    }
    //cout<<cad<<"\n";

    for(int i='a';i<='z';i++){
        if(mejor == ocurrencias[i]){
            cout<<(char)i;
        }
    }
    cout<<"\n";

    
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--)
        solve();
}