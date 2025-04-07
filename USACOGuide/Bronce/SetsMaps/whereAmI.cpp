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
    fin.open("whereami.in");
    fout.open("whereami.out");

    fin>>n;
    string cad;
    fin>>cad;

    string nueva;
    vb sepudo(n+1,1);
    set<string> vistas;

    fore(i,0,n-1){
        fore(j,0,n-1-i){
            nueva = "";
            fore(k,j,j+i){
                nueva+=cad[k];
            }
            if(vistas.count(nueva)){
                sepudo[i+1] = 0;
            }
            vistas.insert(nueva);
        }
    }
    int i=1;
    while(!sepudo[i])i++;
    fout<<i<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}