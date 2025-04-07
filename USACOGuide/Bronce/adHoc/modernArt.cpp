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
    fin.open("art.in");
    fout.open("art.out");
    fin>>n;
    vector<string> mat(n);
    fore(i,0,n-1)fin>>mat[i];
    //fore(i,0,n-1)cout<<mat[i]<<"\n";

    vi cont(10);
    fore(i,0,n-1){
        fore(j,0,n-1){
            cont[mat[i][j]-'0']++;
        }
    }

    /*fore(i,1,9){
        cout<<cont[i]<<",";
    }
    cout<<"\n";*/
    int sup,izq,der,inf;
    
    vvi mapa(10);
    vi indegree(10);
    fore(k,1,9){
        //cout<<"-\n";
        if(!cont[k])continue;
        //cout<<k<<":)\n";
        sup = izq = INT_MAX;
        der = inf = INT_MIN;
        fore(i,0,n-1){
            fore(j,0,n-1){
                if(mat[i][j] == (char)k+'0'){
                    sup = min(sup,i);
                    inf = max(inf,i);
                    izq = min(izq,j);
                    der = max(der,j);
                }
            }
        }
        //cout<<k<<"::"<<sup<<","<<inf<<"__"<<izq<<","<<der<<"\n";
        fore(i, sup, inf){
            fore(j, izq, der){
                if(mat[i][j]!=(char)k+'0' && mat[i][j]!='0'){
                    //cout<<mat[i][j]<<":D\n";
                    mapa[k].pb(mat[i][j]);
                    indegree[mat[i][j]-'0']++;
                }
            }
        }
    }
    /*fore(i,1,9){
        cout<<indegree[i]<<",";
    }
    cout<<"\n";*/
    
    int sol = 0;
    fore(i,1,9){
        if(indegree[i]==0 && cont[i])sol++;
    }
    fout<<sol<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}