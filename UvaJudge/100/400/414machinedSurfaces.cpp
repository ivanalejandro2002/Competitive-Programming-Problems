#include <bits/stdc++.h>

using namespace std;
int solve(int n){
    string cad;
    vector<int> tamano(n);
    for(int i=0;i<n;i++){
        getline(cin,cad);
        int aux = 0;
        for(char co:cad){
            if(co!='X')aux++;
        }
        tamano[i] = aux;
    }
    sort(tamano.begin(),tamano.end());

    int sol = 0;
    int mejor = tamano[0];
    for(int z: tamano){
        sol+=z-mejor;
    }
    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string cad;
    do{
        cin>>n;
        getline(cin,cad);
        if(n==0)break;
        cout<<solve(n)<<"\n";
    }while(n!=0);
}