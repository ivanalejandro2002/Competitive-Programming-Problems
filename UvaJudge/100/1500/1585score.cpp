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

int solve(string &s){
    int sol = 0;
    int x = 0;
    for(char co:s){
        if(co=='X')x=0;
        else sol+=++x;
    }
    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        cout<<solve(s)<<"\n";
    }
}