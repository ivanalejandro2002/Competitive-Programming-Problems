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
    fin.open("angry.in");
    fout.open("angry.out");

    fin>>n;
    vi heno(n);
    fore(i,0,n-1)fin>>heno[i];
    sort(all(heno));

    int mayor = 0;
    fore(i,0,n-1){
        int act = 1;
        int margen = 1;
        int j = i-1;
        //cout<<heno[i] <<": ";
        k = j+1;
        while(j>=0 && heno[j+1]-margen<=heno[j]){
            while(j>=0 && heno[k]-margen<=heno[j]){
                //cout<<heno[j]<<",";
                j--;
                act++;
            }
            margen++;
            k = j+1;
        }

        j = i+1;
        k = j-1;
        margen = 1;
        while(j<n && heno[j-1]+margen>=heno[j]){
            while(j<n && heno[k]+margen>=heno[j]){
                //cout<<heno[j]<<",";
                j++;
                act++;
            }
            margen++;
            k = j-1;
        }
        mayor = max(mayor,act);
        //cout<<"\n";
    }
    fout<<mayor<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}