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
    int n,m,k,l,r,v;
    ifstream fin;
    ofstream fout;
    fin.open("blist.in");
    fout.open("blist.out");
    fin>>n;
    vi leche(1002);
    fore(i,1,n){
        fin>>l>>r>>v;
        leche[l]+=v;
        leche[r]-=v;
    }
    int sol = 0;
    fore(i,1,1000){
        leche[i]+=leche[i-1];
        sol=max(sol,leche[i]);
    }
    fout<<sol<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}