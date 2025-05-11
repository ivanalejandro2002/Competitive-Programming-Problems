#include <bits/stdc++.h>
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

void bend(vi &wire, string &s){
    if(s[1] == 'y'){
        if(s[0]=='+'){
            wire = {-wire[1],wire[0],wire[2]};
        }else{
            wire = {wire[1],-wire[0],wire[2]};
        }
    }else{
        if(s[0] == '+'){
            wire = {-wire[2],wire[1],wire[0]};
        }else{
            wire = {wire[2],wire[1],-wire[0]};
        }
    }
}

void solve(int n){
    vi wire = {1,0,0};

    string s;
    fore(i,2,n){
        cin>>s;
        if(s=="No")continue;
        bend(wire,s);
    }

    if(wire[0]!=0){
        (wire[0]==1)?cout<<"+x\n":cout<<"-x\n";
    }

    if(wire[1]!=0){
        (wire[1]==1)?cout<<"+y\n":cout<<"-y\n";
    }

    if(wire[2]!=0){
        (wire[2]==1)?cout<<"+z\n":cout<<"-z\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    do{
        cin>>n;
        if(n==0)break;
        solve(n);
    }while(n!=0);
}