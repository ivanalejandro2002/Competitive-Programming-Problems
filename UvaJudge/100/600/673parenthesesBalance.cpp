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

bool solve(string &cad){
    stack<char> pila;

    for(char co:cad){
        if(co=='(' || co=='[')pila.push(co);
        if(co==')'){
            if(pila.empty() || pila.top()!='(')return false;
            pila.pop();
        }
        if(co==']'){
            if(pila.empty() || pila.top()!='[')return false;
            pila.pop();
        }
    }
    return pila.empty();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string cad;
    getline(cin,cad);
    while(t--){
        getline(cin,cad);
        (solve(cad))?cout<<"Yes\n":cout<<"No\n";
    }
}