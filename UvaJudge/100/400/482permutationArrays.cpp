#include <bits/stdc++.h>

using namespace std;

vector<int> parse(string &cad){
    vector<int> sol;
    for(int i=0;i<cad.size();i++){
        while(i<cad.size() && cad[i]==' ')i++;
        int aux = 0;
        if(i<cad.size()){
            while(i<cad.size() && cad[i]>='0' && cad[i]<='9'){
                aux*=10;
                aux+=cad[i]-'0';
                i++;
            }
            sol.push_back(aux);
        }
    }
    return sol;
}

vector<pair<int,string > > parseOrder(vector<int> &p, string &cad){
    string s;
    vector<pair<int,string> > sol;
    int act = 0;
    for(int i=0;i<cad.size();i++){
        while(i<cad.size() && cad[i]==' ')i++;
        s = "";
        if(i<cad.size()){
            while(i<cad.size() && cad[i]!=' '){
                s+=cad[i];
                i++;
            }

            sol.push_back({p[act],s});
            act++;
        }
    }
    return sol;
}

void solve(){
    string cad;
    getline(cin,cad);

    vector<int> p = parse(cad);

    getline(cin,cad);

    vector<pair<int,string> > orden;
    orden = parseOrder(p,cad);

    sort(orden.begin(),orden.end());

    for(int i=0;i<orden.size();i++){
        pair<int,string> z = orden[i];
        cout<<z.second<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string cad;
    getline(cin,cad);
    while(t--){
        getline(cin,cad);
        solve();
        if(t>=1)cout<<"\n";
    }
}