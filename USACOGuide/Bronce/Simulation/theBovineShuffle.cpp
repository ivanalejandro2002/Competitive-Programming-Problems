#include <bits/stdc++.h>
#include <fstream>
#define fi first
#define se second
#define pb push_back
#define all(S) S.begin(),S.end()
#define LSOne(S) ((S)&(-S))
#define fore(V,L,R) for(int V = L; V<=R;V++)
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
void solve(){
    int n,m,k;
    ifstream fin;
    ofstream fout;
    fin.open("shuffle.in");
    fout.open("shuffle.out");

    fin>>n;
    vi mapa(n+1);
    fore(i,1,n){
        fin>>m;
        mapa[i]=m;
    }

    map<int,string> codigos;
    string s;
    fore(i,1,n){
        fin>>s;
        codigos[i]=s;
    }

    fore(i,1,n){
        fout<<codigos[mapa[mapa[mapa[i]]]]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}