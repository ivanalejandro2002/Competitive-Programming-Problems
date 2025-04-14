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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

void solve(){
    int n,m,k;
    ifstream fin;
    ofstream fout;
    fin.open("cowsignal.in");
    fout.open("cowsignal.out");
    fin>>n>>m>>k;

    vector<string> mens(n);
    fore(i,0,n)fin>>mens[i];

    fore(i,0,n-1){
        fore(j,0,k-1){
            fore(l,0,m-1){
                fore(z,0,k-1){
                    fout<<mens[i][l];
                }
            }
            fout<<"\n";
        }
    }
    fout.close();
    
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}