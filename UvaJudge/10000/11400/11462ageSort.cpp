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

void solve(int n){
    vi cubeta(100);
    int k;
    fore(i,1,n){cin>>k;cubeta[k]++;}
    bool sacados = 0;
    fore(i,0,100){
        while(cubeta[i]){
            if(sacados)cout<<" ";
            sacados=1;
            cout<<i;
            cubeta[i]--;
        }
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    do{
        cin>>n;
        if(n==0)break;
        solve(n);
    }while(n!=0);
}