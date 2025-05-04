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

int solve(){
    int n;
    cin>>n;
    vi datos(n+1);
    string s;
    int pos = 0;
    fore(i,1,n){
        cin>>s;
        if(s=="LEFT"){
            datos[i]=-1;
            pos--;
        }else if(s=="RIGHT"){
            datos[i]=1;
            pos++;
        }else{
            int k;
            cin>>s>>k;
            datos[i] = datos[k];
            pos+=datos[i];
        }
    }
    return pos;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}