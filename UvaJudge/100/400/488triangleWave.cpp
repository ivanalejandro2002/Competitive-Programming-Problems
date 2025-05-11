#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n,v;
    cin>>n>>v;
    while(v--){
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++)cout<<i;
            cout<<"\n";
        }
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<i;j++)cout<<i;
            cout<<"\n";
        }
        if(v>=1)cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        if(t>=1)cout<<"\n";
    }
}