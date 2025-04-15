#include <bits/stdc++.h>

using namespace std;
void solve(){
    string cad;
    bool usado = 0;
    while(getline(cin,cad)){
        for(char co:cad){
            if(co=='"'){
                if(!usado){
                    cout<<"``";
                }else{
                    cout<<"''";
                }
                usado = !usado;
            }else cout<<co;
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}