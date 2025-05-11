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
void solve(double h,double u, double d, double f){
    double height =0;
    int day = 0;
    f/=100;
    f = u*f;
    while(height<h && height>=0){
        day++;
        height+=u;
        if(height>h){
            cout<<"success on day "<<day<<"\n";
            return;
        }
        height-=d;
        u-=f;
        if(u<0)u= 0;
    }
    cout<<"failure on day "<<day<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double h,u,d,f;
    do{
        cin>>h>>u>>d>>f;
        if(h==0 && u==0 && d==0 && f==0)break;
        solve(h,u,d,f);
    }while(h!=0 || u!=0 || d!=0 || f!=0);
}