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
typedef long long int ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int solve(int n, int b, int h , int w){
    int paux,d;
    int minimo = INT_MAX;
    
    bool posible;
    fore(i,1,h){
        posible = 1;
        cin>>paux;
        paux*=n;

        if(paux>b)posible = 0;
        bool s = 0;
        fore(j,1,w){
            cin>>d;
            if(d>=n)s=1;
        }

        posible&=s;

        if(posible)minimo = min(minimo,paux);
    }

    if(minimo == INT_MAX)return -1;
    return minimo;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,b,h,w;
    while(cin>>n>>b>>h>>w){
        int s = solve(n,b,h,w);
        if(s<0)cout<<"stay home\n";
        else cout<<s<<"\n";
    }
}