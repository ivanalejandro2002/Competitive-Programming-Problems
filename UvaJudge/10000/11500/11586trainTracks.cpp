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

string solve(string s){
    int M,F;
    M = F = 0;

    for(char co:s){
        if(co=='M')M++;
        if(co=='F')F++;
    }
    if(M==F && min(M,F)>1)return "LOOP";
    return "NO LOOP";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string cad;
    getline(cin,cad);
    while(t--){
        getline(cin,cad);
        if(cad.size()==0){
            t++;
            continue;
        }
        cout<<solve(cad)<<"\n";
    }
}