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
int busca(int origen, int obj, int dir){
    if(origen==obj)return 0;
    int delta = 0;
    bool terminado = 0;
    int sol = 0;
    int ant = origen;
    while(1){
        ant = origen+delta;
        if(delta==0)delta=1;
        else delta*=-2;
        if(dir>0 && origen+delta>=obj)return sol+abs(ant-obj);
        if(dir<0 && origen+delta<=obj)return sol+abs(ant-obj);

        sol+=abs(ant-(origen+delta));
    }
    return sol;
}
void solve(){
    ifstream fin;
    ofstream fout;
    fin.open("lostcow.in");
    fout.open("lostcow.out");
    int n,m,k;
    fin>>n>>m;
    int dir = 1;
    if(n > m )dir=-1;

    fout<<busca(n,m,dir);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}