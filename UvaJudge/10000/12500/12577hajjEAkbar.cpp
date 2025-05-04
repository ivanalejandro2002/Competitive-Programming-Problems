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

string solve(string s){
    if(s=="Hajj")return "Hajj-e-Akbar";
    return "Hajj-e-Asghar";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int i=1;
    do{
        cin>>s;
        if(s=="*")break;
        cout<<"Case "<<i<<": "<<solve(s)<<"\n";
        i++;
    }while(s!="*");
}