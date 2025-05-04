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

string solve(int a,int b, int c){
    if(a+b+c == 0 || a+b+c == 3)return "*";
    if(a+b+c==1){
        if(a==1)return "A";
        if(b==1)return "B";
        return "C";
    }
    if(a==0)return "A";
    if(b==0)return "B";
    return "C";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,c;
    while(cin>>a>>b>>c){
        cout<<solve(a,b,c)<<"\n";
    }
}