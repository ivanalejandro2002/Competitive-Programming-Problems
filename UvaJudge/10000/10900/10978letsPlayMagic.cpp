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
    int m,k;
    vector<string> cartas(n);

    int idx = -1;
    string id,nom;
    int disp = n;
    fore(i,1,n){
        cin>>id>>nom;
        int w = (nom.size()-1)%disp+1;
        while(w>0){
            idx++;
            if(idx>=n)idx-=n;
            if(cartas[idx].size()==0)w--;
        }
        disp--;
        cartas[idx] = id;
    }

    fore(i,0,n-1){
        cout<<cartas[i];
        if(i<n-1)cout<<" ";
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