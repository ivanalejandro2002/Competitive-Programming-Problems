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
    vi datos(n+1);
    fore(i,1,n)cin>>datos[i];
    set<int> cosos;
    fore(i,2,n){
        if(abs(datos[i]-datos[i-1])<n){
            cosos.insert(abs(datos[i]-datos[i-1]));
        }
    }
    if(cosos.size()==n-1){
        cout<<"Jolly\n";
    }else{
        cout<<"Not jolly\n";
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        solve(n);
    }
}