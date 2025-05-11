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
    char co;
    int vidas = 3;
    vector<char> cosos(n+1);
    fore(i,1,n)cin>>cosos[i];
    fore(i,1,n){
        co = cosos[i];
        if(co=='W'){
            vidas = 3;
        }else{
            vidas--;
            if(vidas==0)return i;
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    fore(i,1,t){
        int s = solve();
        cout<<"Case "<<i<<": ";
        (s>0)?cout<<s<<"\n":cout<<"Yay! Mighty Rafa persists!\n";
    }
}