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
    fin.open("cowqueue.in");

    fin>>n;
    vpii vacas(n);
    fore(i,0,n-1)fin>>vacas[i].fi>>vacas[i].se;
    sort(all(vacas));
    int tactual = 0;
    fore(i,0,n-1){
        if(tactual<vacas[i].fi)tactual = vacas[i].fi;
        tactual+=vacas[i].se;
    }
    fout.open("cowqueue.out");
    fout<<tactual<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}