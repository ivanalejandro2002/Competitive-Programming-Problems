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
    int m,a,r,g,i,t;
    m=a=r=g=i=t=0;
    string cad;
    getline(cin,cad);
    for(char co:cad){
        if(co=='M')m++;
        if(co=='A')a++;
        if(co=='R')r++;
        if(co=='G')g++;
        if(co=='I')i++;
        if(co=='T')t++;
    }
    cout<<min(m,min(a/3,min(r/2,min(g,min(i,t)))))<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    string s;
    cin>>t;
    getline(cin,s);
    while(t--)
        solve();
}