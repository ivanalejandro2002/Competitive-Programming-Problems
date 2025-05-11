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

int solve(string &mapa){

    map<int,int> anteriores;
    set<int> visitados;
    int nivel = 0;
    int area = 0;
    int i=0;
    visitados.insert(0);
    anteriores[0] = -1;
    for(char co:mapa){
        if(co=='/'){
            nivel++;
            if(visitados.count(nivel))area+=i-anteriores[nivel]-1;
        }else if(co=='\\') nivel--;
        visitados.insert(nivel);
        anteriores[nivel] = i;
        i++;
    }

    return area;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string orografia;
    while(n--){
        cin>>orografia;
        cout<<solve(orografia)<<"\n";
    }
}