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
    fin.open("sleepy.in");
    fout.open("sleepy.out");
    fin>>n;
    set<int> faltan;
    fore(i,1,n){
        faltan.insert(i);
    }
    int mayor = 0;
    fore(i,1,n){
        fin>>k;
        if(*faltan.begin()==k){
            faltan.erase(k);
            continue;
        }
        mayor = i;
        faltan.erase(k);
    }
    fout<<mayor<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}