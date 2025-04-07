#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a,b;
    cin>>a>>b;

    char ultimoA,ultimoB;
    ultimoA = a.back();
    ultimoB = b.back();

    if(ultimoA != ultimoB){
        if(ultimoA == 'S'){
            cout<<"<\n";
            return;
        }
        if(ultimoA == 'L'){
            cout<<">\n";
            return;
        }
        if(ultimoB == 'S'){
            cout<<">\n";
            return;
        }else{
            cout<<"<\n";
            return;
        }
    }else{
        int tamanoA,tamanoB;
        tamanoA = a.size();
        tamanoB = b.size();

        if(ultimoA == 'S'){
            if(tamanoA < tamanoB){
                cout<<">\n";
                return;
            }else if(tamanoA > tamanoB){
                cout<<"<\n";
            }else{
                cout<<"=\n";
            }
        }else if(ultimoA =='L'){
            if(tamanoA < tamanoB){
                cout<<"<\n";
                return;
            }else if(tamanoA > tamanoB){
                cout<<">\n";
            }else{
                cout<<"=\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}