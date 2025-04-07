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
    fin.open("traffic.in");
    fout.open("traffic.out");

    fin>>n;
    int menor = 0;
    int mayor = 0;
    int l,r;
    string op;

    bool encontrado= 0;
    int lmin,lmax;
    while(n--){
        fin>>op>>l>>r;
        if(!encontrado){
            if(op.size()==2){
                menor += l;
                mayor += r;
            }else if(op.size() == 3){
                menor -=r;
                mayor -=r;
            }else{
                encontrado = 1;
                fout<<min(max(menor,l),max(0,r-mayor))<<" "<<r-menor<<"\n";
                lmin = max(menor,l);
                lmax = r;
            }
        }else{
            if(op.size()==2){
                lmin+=l;
                lmax+=r;
            }else if(op.size()==3){
                lmin-=r;
                lmax-=l;
            }else{
                lmin = max(lmin,l);
                lmax = min(lmax,r);
            }
        }
    }
    fout<<lmin<<" "<<lmax<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}