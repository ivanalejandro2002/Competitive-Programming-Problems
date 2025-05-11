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
set<string> diccionario;
void solve(string &s){
    string aux = "";
    for(char co:s){
        if(co>='a' && co<='z'){
            aux+=co;
        }else if(co>='A' && co<='Z'){
            aux+=(co+'a'-'A');
        }else{
            if(aux.size()==0)continue;
            diccionario.insert(aux);
            aux = "";
        }
    }
    if(aux.size()>0)diccionario.insert(aux);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while(getline(cin,s)){
        solve(s);
    }
    for(auto z:diccionario){
        cout<<z<<"\n";
    }
}