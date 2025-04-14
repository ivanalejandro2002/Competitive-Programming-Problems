#include <bits/stdc++.h>
#define MOD (long long int)(1e9 + 7)
using namespace std;
typedef long long int ll;
bool solve(ll w, ll aum, vector<ll> &alturas){
    ll n,i,a,k,t,h;
    //cout<<MOD<<"\n";
    h = 3e9+2+aum;
    int sig=0;
    int dosig=0;
    for(i=0;i<w;i++){
        a = alturas[i];
        if(h-a-(ll)sig<0){
            return 0;
        }
        if((h-a-(ll)sig)%2==1){
            sig++;
        }else{
            if(sig>0)sig--;
        }
    }
    return !sig;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll w;
    cin>>w;
    bool par,impar;

    vector<ll> datos(w);
    for(int i=0;i<w;i++)cin>>datos[i];

    par = solve(w,0,datos);
    impar = solve(w,1,datos);

    (par || impar)?cout<<"YES\n":cout<<"NO\n";
    return 0;
}