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
bool solve(double a,double b, double c, double w){
    return(w<=7 && ((a<=56 && b<=45 && c<=25) || (a+b+c)<=125));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    int cont = 0;
    double a,b,c,w;
    while(t--){
        cin>>a>>b>>c>>w;
        bool s = solve(a,b,c,w);
        (s)?cout<<"1\n":cout<<"0\n";
        cont+=s;
    }
    cout<<cont<<"\n";
}