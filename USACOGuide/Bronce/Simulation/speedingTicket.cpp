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
    int n,m,k,l,v;
    vi velocidad(102);
    ifstream fin;
    ofstream fout;
    fin.open("speeding.in");
    fout.open("speeding.out");
    fin>>n>>m;
    int d=0;
    int sol = 0;
    fore(i,1,n){
        fin>>l>>v;
        while(l--){
            d++;
            velocidad[d] = v;
        }
    }
    d=0;
    fore(i,1,m){
        fin>>l>>v;
        while(l--){
            d++;
            sol = max(sol,v-velocidad[d]);
        }
    }
    fout<<sol<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}